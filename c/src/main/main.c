#include "150-evaluate-reverse-polish-notation/150.h"
#include <stdio.h>

#define inputSize(x) x
#define inputColSize(x) x

int main(int args, char **arv) {
    char *input[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int excepted = 22;
    int tokenSize = 13;

    printf("ret: %d", evalRPN(input, tokenSize));
}
