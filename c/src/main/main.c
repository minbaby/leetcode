#include <stdlib.h>
#include <stdio.h>
#include "22-generate-parentheses/22.h"

int main(int args, char **arv) {
    int n = 7;
    int returnSize = 0;
    char **ret = generateParenthesis(n, &returnSize);

    char *expected[] = {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
    };

    for (int i = 0; i < returnSize; ++i) {
        printf("%s---", ret[i]);
    }

}

