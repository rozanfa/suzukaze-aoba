#include "board.hpp"

using namespace std;

board::board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            content[i][j] = ' ';
        }
    }
}

char board::getMark(int i, int j){
    return content[i][j];
}

int board::checkStatus(){
    for(int i = 0; i < 3; i++){
        if(content[i][0] == content[i][1] && content[i][1] == content[i][2]){
            if (content[i][0] == 'X'){
                return 'c';
            }
            if (content[i][0] == 'O'){
                return 's';
            }
        }
        if(content[0][i] == content[1][i] && content[1][i] == content[2][i]){
            if (content[0][i] == 'X'){
                return 'c';
            }
            if (content[0][i] == 'O'){
                return 's';
            }
        }
    }
    if(content[0][0] == content[1][1] && content[1][1] == content[2][2]){
        if (content[1][1] == 'X'){
            return 'c';
        }
        if (content[1][1] == 'O'){
            return 's';
        }
    }
    if(content[0][2] == content[1][1] && content[1][1] == content[2][0]){
        if (content[1][1] == 'X'){
            return 'c';
        }
        if (content[1][1] == 'O'){
            return 's';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (content[i][j] == ' ') {
                return 0;
            }
        }
    }
    return -1;
}

void board::makeMove(int i, int j, char mark){
    if (content[i][j] == ' '){
        content[i][j] = mark;
    }
}

void board::display(){
    cout << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << content[i][j];
            if (j != 2) {
                cout << " | ";
            }
        }
        if (i != 2) {
            cout << endl << "---------" << endl;
        }
    }
    cout << endl;
    cout << endl;
}

bool board::isMoveValid(int i, int j){
    if (i < 3 && i >= 0 && j < 3 && j >= 0 && content[i][j] == ' ') {
        return true;
    }
    return false;
}