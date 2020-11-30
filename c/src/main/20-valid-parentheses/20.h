#ifndef LEET_CODE_20_H
#define LEET_CODE_20_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <utstack.h>

//@see https://leetcode-cn.com/problems/valid-parentheses/
bool isValid(char * s);
bool isValid2(char * s);

typedef struct el {
    char c;
    struct el *next;
} el;

#endif // LEET_CODE_20_H