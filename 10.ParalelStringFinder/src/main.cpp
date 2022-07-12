#include "ll.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <omp.h>

#define BLOCKSIZE 254
#define FILESIZE 4096

bool matchStringInBlock(char* text, char* pattern){
    for (int i = 0; i < BLOCKSIZE; i++){
        int j = 0;
        while (pattern[j] != '\0' && pattern[i] != '\0' && text[i+j] == pattern[j]){
            j++;
        }
        if (pattern[j] == '\0') {
            return true;
        }
    }
    return false;
}

void displayFile(int fileno){
    char filePath[BLOCKSIZE];
    char result[BLOCKSIZE];
    sprintf(filePath, "/proc/self/fd/%d", fileno);
    memset(result, 0, sizeof(result));
    readlink(filePath, result, sizeof(result));
    printf("%s\n", result);
}

int count = 0;

int main(int argc, char** args){
    if (argc < 2){
        printf("Usage: %s <file>\n", args[0]);
        return 1;
    }
    printf("String yang dicari: %s\n", args[1]);
    printf("Hasil:\n");
    char* stringToSearch = args[1];
    
    char* path = new char[2];
    path[0] = '.';
    path[1] = '\0';
    ll* list = ll::createListOfFiles(path);
    double initialTime = omp_get_wtime();
    pid_t pid;
    node* p = list->getHead();
    int child = 0;

    while (p){
        // Mencari file secara multiprocessing
        pid = fork();
        if (pid != 0){
            // Untuk parent
            child++;
            p = p->getNext();
        }
        else {
            // Child keluar dari loop
            break;
        }
    }

    if (pid != 0){
        // Untuk parent
        // Menunggu semua child
        while (child > 0){
            int stat;
            pid_t cid;
            cid = wait(&stat);
            child--;
            count += WEXITSTATUS(stat);
        }
        printf("-------------------------------------------------\n");
        printf("Jumlah ditemukan: %d\n", count);
    }
    else {
        // Untuk child
        int fd = p->getData();
        char buffer[FILESIZE];
        FILE* fp = fdopen(fd, "rb");
        fread(buffer, 1, FILESIZE, fp);
        int len = strlen(stringToSearch);
        int i = 0;

        omp_set_num_threads(4); // Jumlah thread yang digunakan
        bool found = false;

        // Mencari stringToSearch dalam buffer secara multithreading
        #pragma omp parallel for shared(found) private(i) schedule(dynamic)
        for(i = 0; i<FILESIZE; i+=BLOCKSIZE){
            if (buffer[i] && !found){
                // printf("Thread %d: %d----------------------------------------\n", omp_get_thread_num(), i);
                // char* content = new char[BLOCKSIZE];
                // memcpy(content, buffer+i, BLOCKSIZE);
                // printf("%s\n", content);
                if (matchStringInBlock(&buffer[i], stringToSearch)) {
                    #pragma omp critical 
                    {
                        if (!found){
                            found = true;
                            displayFile(fd);
                        }
                    }
                }
            }
        }

        if (!found){
            exit(0);
        }
        else {
            exit(1);
        }
        fclose(fp);
    }


    
}