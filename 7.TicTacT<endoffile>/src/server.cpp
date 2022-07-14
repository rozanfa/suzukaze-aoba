#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include"board.hpp"

using namespace std;

int main(){
    board b;
    int ssid, fd1;
    int msgbyte;
    int status = 0, choice;

    ssid = socket(AF_INET, SOCK_STREAM, 0);
    if (ssid == -1) {
        cout << "Error in creating socket" << endl;
        exit(1);
    }
    cout << "Socket created successfully" << endl;
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost
    if (bind(ssid, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        cout << "Error in binding" << endl;
        exit(1);
    }
    cout << "Binding successful" << endl;
    listen(ssid, 5);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    cout << "Waiting for opponent to connect..." << endl;
    fd1 = accept(ssid, (struct sockaddr*)&client_addr, &client_addr_len);
    if (fd1 == -1) {
        cout << "Error in accepting" << endl;
        exit(1);
    }
    cout << "Connection accepted" << endl;

    while (status == 0){
        b.display();
        cout << "Waiting for opponent's move..." << endl;
        msgbyte = recv(fd1, &choice, sizeof(choice), 0);
        if (msgbyte == -1) {
            cout << "Error in receiving" << endl;
            exit(1);
        }
        cout << "Opponent's move: " << choice + 1 << endl;
        b.makeMove(choice/3, choice%3, CLIENTMARK);
        b.display();
        status = b.checkStatus();
        if (status == 'c'){
            cout << "You lose!" << endl;
            break;
        }
        if (status == -1) break;
        cout << "You : O" << endl;
        cout << "Opponent : X" << endl;
        cout << "Your turn" << endl;
        cout << "Enter your move [1-9]: ";
        cin >> choice;
        choice--;
        while (!b.isMoveValid(choice/3, choice%3)){
            cout << "Invalid move. Enter your move [1-9]: ";
            cin >> choice;
            choice--;
        }

        b.makeMove(choice/3, choice%3, SERVERMARK);
        b.display();
        msgbyte = send(fd1, &choice, sizeof(choice), 0);
        if (msgbyte == -1) {
            cout << "Error in sending" << endl;
            exit(1);
        }
        status = b.checkStatus();
        if (status == 's'){
            cout << "You win!" << endl;
            break;
        }
    }
    if (status == -1){
        cout << "Draw!" << endl;
    }
    close(fd1);
    close(ssid);
    return 0;
}