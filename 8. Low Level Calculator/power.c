#include "power.h"

int power(int a, int b) {
    if (b < 0){
        return 0;
    }
    int result = 1;
    powerloop:
    if (b == 0) {
        return result;
    }
    else {
        result = times(result, a);
        b = subtract(b, 1);
        goto powerloop;
    }
    return result;
}