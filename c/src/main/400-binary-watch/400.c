#include "400.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

int map[] = {
        1, 2, 4, 8,
        1, 2, 4, 8, 16, 32,
};

static void backtrace(char **res, int num, int *returnSize, int start, int hour, int min) {
    if (num == 0) {
        if (hour > 11 || min > 59) {
            return;
        }

        char minStr[3];
        if (min < 10) {
            sprintf(minStr, "0%d", min);
        } else {
            sprintf(minStr, "%d", min);
        }

        char *str = (char *) malloc(sizeof(char) * 6);
        memset(str, '\0', 6);
        sprintf(str, "%d:%s", hour, minStr);

        res[*returnSize] = str;
        (*returnSize)++;

        return;
    }

    for (int i = start; i < 10; ++i) {
        int _hour = hour;
        int _min = min;

        if (i < 4) {
            _hour += map[i];
        } else {
            _min += map[i];
        }

        backtrace(res, num - 1, returnSize, i + 1, _hour, _min);
    }
}

char **readBinaryWatch(int num, int *returnSize) {
    char **res = (char **) malloc(sizeof(char *) * MAX_SIZE);
    *returnSize = 0;
    backtrace(res, num, returnSize, 0, 0, 0);
    return res;
}

