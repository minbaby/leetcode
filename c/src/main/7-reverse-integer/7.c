#include "7.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

// 最简单的方法，数字转字符串，然后反转，然后字符串转数字
int reverse_(int x) {
    if (x == INT_MIN) {
        return 0;
    }

    char ret[11] = {};
    int index = 0;
    int f = 0;
    if (x < 0) {
        x = -x;
        f = 1;
    }
    int tmp = x;
    while (tmp) {
        ret[index] = (char) (tmp % 10 + '0');
        tmp = tmp / 10;
        index++;
    }

    long y = strtol(ret, NULL, 10);

    if (y > INT_MAX || y < INT_MIN) {
        y = 0;
    }

    return (int) (f == 1 ? -y : y);
}

int reverse(int x) {
    long ret = 0;

    while (x) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }

    if (ret>INT_MAX || ret < INT_MIN) {
        return 0;
    }

    return (int) ret;
}