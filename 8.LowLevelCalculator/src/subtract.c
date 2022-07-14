#include "subtract.h"

int subtract(int a, int b){
    subtractloop:
    if(b == 0){
        return a;
    }
    else{
        unsigned int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
        goto subtractloop;
    }
}

// int main(){
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     printf("Subtract of %d and %d is %d\n", a, b, subtract(a, b));
//     return 0;
// }