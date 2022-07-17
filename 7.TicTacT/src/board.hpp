#include <iostream>
using namespace std;

#define CLIENTMARK 'X'
#define SERVERMARK 'O'

class board{
    private:
        char content[3][3];
    public:
        board();
        char getMark(int, int);
        int checkStatus();
        void makeMove(int, int, char);
        char getContent(int, int);
        void display();
        bool isMoveValid(int, int);
};