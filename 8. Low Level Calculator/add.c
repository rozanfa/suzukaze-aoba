#include "add.h"

int add(int a, int b){
    addloop:
    if(b == 0){
        return a;
    }
    else{
        unsigned int carry = a & b;
        a = a ^ b;
        b = carry << 1;
        goto addloop;
    }
}

// int main(){
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     printf("Sum of %d and %d is %d\n", a, b, add(a, b));
//     return 0;
// }