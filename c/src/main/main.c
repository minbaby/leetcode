#include <stdio.h>
#include <stdbool.h>
#include "20-valid-parentheses/20.h"

int main(int args, char **arv) {
    char *input = "((";
    bool ret = isValid(input);

    printf("<><>%d<><>", ret);
}