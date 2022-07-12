#include <iostream>
#include <dirent.h>
#include <string.h>

class node {
    public:
        node(){
            next = NULL;
            data = 0;
        }
        node(int data){
            next = NULL;
            this->data = data;
        }
        node(const node& n){
            next = NULL;
            this->data = n.data;
        }
        ~node(){
            next = NULL;
            data = 0;
        }
        int const getData(){
            return data;
        }
        void setData(int){
            data = data;
        }
        node *getNext(){
            return this->next;
        }
        void setNext(node* n){
            this->next = n;
        }
    private:
        int data;
        node* next;
};

class ll {
    public:
        ll(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ll(int data){
            head = new node(data);
            tail = NULL;
            size = 0;
        }
        ~ll(){
            node *temp = head;
            while(temp != NULL){
                node *temp2 = temp->getNext();
                delete temp;
                temp = temp2;
            }
        }
        node* getHead(){
            return head;
        }
        node* getTail(){
            return tail;
        }
        int getSize(){
            return size;
        }
        void add(int data){
            if(head == NULL){
                head = new node(data);
                tail = head;
            }
            else{
                tail->setNext(new node(data));
                tail = tail->getNext();
            }
            size++;
        }
        void add(node *n){
            if(head == NULL){
                this->head = n;
                this->tail = head;
            }
            else{
                this->tail->setNext(n);
                this->tail = this->tail->getNext();
            }
            size++;
        }
        void add(ll *l){
            if(head == NULL){
                head = l->getHead();
                tail = l->getTail();
            }
            else{
                tail->setNext(l->getHead());
                tail = l->getTail();
            }
            size += l->getSize();
        }
        int getLastData(){
            return tail->getData();
        }
        static ll* createListOfFiles(char* path){
            ll* list = new ll();
            DIR *dir = opendir(path);
            if (dir != NULL){
                char* dirpath = new char[512];
                struct dirent* ent = readdir(dir);
                while (ent != NULL){
                    sprintf(dirpath, "%s/%s", path, ent->d_name);
                    if(ent->d_type == DT_DIR){
                        if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
                            list->add(createListOfFiles(dirpath));
                        }
                    }
                    else{
                        list->add(new node(fileno(fopen(dirpath, "r"))));
                    }
                    ent = readdir(dir);
                }
            }
            closedir(dir);
            return list;
        }
    private:
        node *head;
        node *tail;
        int size;
};