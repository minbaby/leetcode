#include <ctype.h>
#include <limits.h>
#include "8.h"

int myAtoi(char *s) {
    for (; *s == ' '; s++) {}

    int f = 1;
    switch (*s) {
        case '-':
            f = -1;
            s++;
            break;
        case '+':
            s++;
            break;
    }

    long ret = 0;
    while (*s != '\0') {
        if (!isdigit(*s)) {
            break;
        }
        if ((int) ret != ret) {
            return f == -1 ? INT_MIN : INT_MAX;
        }
        ret = ret * 10 + (*s - '0');
        s++;
    }

    ret = ret * f;
    if (ret > INT_MAX) return INT_MAX;
    if (ret < INT_MIN) return INT_MIN;

    return (int) ret;
}