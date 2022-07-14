#include "div.h"

int div(int a, int b){
    int sign = 0;
    if(b < 0){
        sign = sign ^ 1;
        b = negate(b);
    }
    if(a < 0){
        sign = sign ^ 1;
        a = negate(a);
    }
    int result = 0;
    divloop:
    if (a < b){
        if (sign == 1){
            return negate(result);
        }
        else{
            return result;
        }
    }
    else {
        result++;
        a = subtract(a, b);
        goto divloop;
    }
}

// int main(){
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     printf("Division of %d and %d is %d\n", a, b, div(a, b));
//     return 0;
// }