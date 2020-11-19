#include "17.h"
#include <stdlib.h>
#include <string.h>

char phoneMap[11][5] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
};

char *digits_tmp;
int digits_size;

char **combinations;
int combinations_size;

char *combination;
int combination_size;

void backtrack(int index) {
    if (index == digits_size) {
        size_t t = sizeof(char) * (combination_size+1);
        char *tmp = (char *) malloc(t);
        memset(tmp, '\0', t);
        memcpy(tmp, combination, t);
        combinations[combinations_size++] = tmp;
        return;
    }

    char digit = digits_tmp[index];
    char *letters = phoneMap[digit - '0'];
    int len = (int) strlen(letters);
    for (size_t i = 0; i < len; i++) {
        combination[combination_size++] = letters[i];
        combination[combination_size] = 0;
        backtrack(index + 1);
        combination[--combination_size] = 0;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize) {
    combination_size = combinations_size = 0;
    digits_tmp = digits;
    digits_size = (int) strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return combinations;
    }

    int num = 1;
    for (size_t i = 0; i < digits_size; i++) {
        num *= 4;
    }

    combinations = (char **) malloc(sizeof(char *) * num);
    combination = (char *) malloc(sizeof(char *) * digits_size);
    backtrack(0);

    *returnSize = combinations_size;
    return combinations;
}