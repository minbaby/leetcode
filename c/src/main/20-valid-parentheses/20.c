#include <string.h>
#include "20.h"

// 如果是其他语言，这个地方一般会用栈来解决，C的话大多数会使用数据来处理。
bool isValid2(char *s) {
    el *stack = NULL;
    size_t len = strlen(s);

    for (int i = 0; i < len; ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            el *tmp = (el *) malloc(sizeof(el));
            tmp->c = s[i];
            STACK_PUSH(stack, tmp);
        } else {
            el *tmp = NULL;
            if (STACK_EMPTY(stack)) {
                return false;
            }

            STACK_POP(stack, tmp);
            char t = tmp->c;
            free(tmp);

            if ((s[i] == ')' && t != '(') || (s[i] == ']' && t != '[') || (s[i] == '}' && t != '{')) {
                while (!STACK_EMPTY(stack)) {
                    STACK_POP(stack, tmp);
                    free(tmp);
                }
                return false;
            }
        }
    }

    bool empty = STACK_EMPTY(stack);
    if (!empty) {
        el *tmp = NULL;
        while (!STACK_EMPTY(stack)) {
            STACK_POP(stack, tmp);
            free(tmp);
        }
    }

    return empty;
}

bool isValid(char *s) {
    size_t len = strlen(s);

    char stack[len];
    memset(stack, '\0', len);
    int index = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack[index] = s[i];
            index++;
        } else {
            if (strlen(stack) == 0) {
                return false;
            }

            char t = stack[index - 1];

            if ((s[i] == ')' && t != '(') || (s[i] == ']' && t != '[') || (s[i] == '}' && t != '{')) {
                return false;
            }

            stack[index - 1] = '\0';
            index--;
        }
    }

    return index == 0;
}