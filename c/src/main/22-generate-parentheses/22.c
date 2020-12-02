#include <string.h>
#include "22.h"

#define MAX_SIZE 1430

static void backtrace(
        int n,
        int *returnSize,
        char *str,
        int index,
        char **result,
        int lCount,
        int rCount
) {
    // 括号用完了
    if (lCount == n && rCount == n) {
        result[*returnSize] = (char *) malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[*returnSize], str);
        (*returnSize)++;
        return;
    }

    // 先用左括号
    if (lCount < n) {
        str[index] = '(';
        backtrace(n, returnSize, str, index + 1, result, lCount + 1, rCount);
        str[index] = '\0';
    }

    // 后用右括号
    if (rCount < lCount && rCount < n) {
        str[index] = ')';
        backtrace(n, returnSize, str, index + 1, result, lCount, rCount + 1);
        str[index] = '\0';
    }
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0;

    char **result = (char **) malloc(sizeof(char) * MAX_SIZE);
    memset(result, '\0', sizeof(char) * MAX_SIZE);

    char *str = (char *) malloc(sizeof(char) * (2 * n + 1));
    memset(str, '\0', sizeof(char) * (2 * n + 1));

    backtrace(n, returnSize, str, 0, result, 0, 0);

    free(str);

    return result;
}