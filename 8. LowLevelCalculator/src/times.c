#include "times.h"

int times(int a, int b) {
    unsigned char sign = 0;
    if (b<0){
        sign = sign ^ 1;
        b = negate(b);
    }
    if (a<0){
        sign = sign ^ 1;
        a = negate(a);
    }
    int result = 0;
    timesloop:
    if (b == 0) {
        if (sign == 1) {
            return negate(result);
        }
        else {
            return result;
        }
    }
    else {
        result = add(result, a);
        b--;
        goto timesloop;
    }
}

// int main() {
//     int a = -3;
//     int b = 9;
//     int result = times(a, b);
//     printf("%d\n", result);
//     return 0;
// }