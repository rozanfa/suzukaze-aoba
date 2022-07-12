#include "calculator.h"

void ignore_space(char **str) {
    ignorespaceloop:
    if (**str == ' '){
        (*str)++;
        goto ignorespaceloop;
    }
}

int parse_int(char **str) {
    int result = 0;
    int sign = 0;
    tointloop:
    if (**str == '-') {
        (*str)++;
        sign = sign ^ 1;
        goto tointloop;
    }
    else if (**str < '0' || **str > '9') {
        if (sign == 1) {
            return negate(result);
        }
        else {
            return result;
        }
    }
    else {
        result = 10 * result + (**str - '0');
        (*str)++;
        goto tointloop;
    }
}

unsigned char isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


int main(){
    printf("Enter an expression: ");
    char input[1000];
    gets(input);
    int result = 0;
    char* p = input;
    ignore_space(&p);
    if (*p < '0' || *p > '9') {
        goto invalidinput;
    }
    result = parse_int(&p);

    while (1){
        mainloop:
        ignore_space(&p);
        if (*p!='\0'){
            if (*p == '+'){
                p++;
                ignore_space(&p);
                result = add(result, parse_int(&p));
            }
            else if (*p == '-'){
                p++;
                ignore_space(&p);
                result = subtract(result, parse_int(&p));
            }
            else if (*p == '*'){
                p++;
                ignore_space(&p);
                result = times(result, parse_int(&p));
            }
            else if (*p == '/'){
                p++;
                ignore_space(&p);
                result = div(result, parse_int(&p));
            }
            else if (*p == '^'){
                p++;
                ignore_space(&p);
                result = power(result, parse_int(&p));
            }
            else {
                goto invalidinput;
            }
            goto mainloop;
        }
        printf("= %d ", result);
        gets(p);
        goto mainloop;
    }


    invalidinput:
    printf("Error: invalid input\n");


    exit:
    return 0;
}