#include <stdio.h>
#include <stdlib.h>
#include "12-integer-to-roman/12.h"

int main(int args, char **arv) {
    int height[] = {2,3,4,5,18,17,6};
    int heightSize = 7;
    int expected = 17;

    char *x = intToRoman(1994);

    printf("%s\n", x);
    free(x);
}