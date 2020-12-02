#include "22.h"
#include <criterion/criterion.h>
#include "../../utils.h"

static int cmp(char *a, char *b) {
    return *a == *b ? 0 : 1;
}

Test(generateParenthesis, a001) {
    int n = 3;
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
        cr_assert(expected[i] != ret[i], "%s-%s", expected[i], ret[i]);
        free(ret[i]);
    }

    free(ret);
}