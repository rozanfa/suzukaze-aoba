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
    int csid;
    int msgbyte;
    int status = 0, choice;
    
    csid = socket(AF_INET, SOCK_STREAM, 0);
    if (csid == -1) {
        cout << "Error in creating socket" << endl;
        exit(1);
    }
    cout << "Socket created successfully" << endl;
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(5000);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //localhost
    if (connect(csid, (struct sockaddr*)&client_addr, sizeof(client_addr)) == -1) {
        cout << "Error in connecting" << endl;
        exit(1);
    }
    cout << "Connection successful" << endl;
    while (status == 0){
        b.display();
        cout << "You : X" << endl;
        cout << "Opponent : O" << endl;
        cout << "Your turn" << endl;
        cout << "Enter your move [1-9]: ";
        cin >> choice;
        choice--;
        while (!b.isMoveValid(choice/3, choice%3)){
            cout << "Invalid move. Enter your move [1-9]: ";
            cin >> choice;
            choice--;
        }
        b.makeMove(choice/3, choice%3, CLIENTMARK);
        b.display();
        msgbyte = send(csid, &choice, sizeof(choice), 0);
        status = b.checkStatus();
        if (status == 'c'){
            cout << "You win!" << endl;
            break;
        }
        if (status == -1) break;
        if (msgbyte == -1) {
            cout << "Error in sending" << endl;
            exit(1);
        }
        cout << "Waiting for oppenent's move..."  << endl;
        msgbyte = recv(csid, &choice, sizeof(choice), 0);
        if (msgbyte == -1) {
            cout << "Error in receiving" << endl;
            exit(1);
        }
        cout << "Opponent's move: " << choice + 1 << endl;
        b.makeMove(choice/3, choice%3, SERVERMARK);
        b.display();
        status = b.checkStatus();
        if (status == 's'){
            cout << "You lose!" << endl;
            break;
        }
    }
    if (status == -1){
        cout << "Draw!" << endl;
    }
    close(csid);
    return 0; 
}