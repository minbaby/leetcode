#include "../utils.h"
#include "6-zigzag-conversion/6.h"
#include <stdio.h>
#include <stdlib.h>

int main(int args, char **arv) {
    char *s = "LEETCODEISHIRING";
    int numRows = 100;
    char *o = "LCIRETOESIIGEDHN";

    char * ret = convert(s, numRows);
    printf("[%s]", ret);
    free(ret);
}