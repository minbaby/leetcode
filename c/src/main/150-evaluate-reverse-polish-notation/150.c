#include "150.h"
#include <utstack.h>
#include <stdio.h>

struct Node150 {
    char value[100];
    struct Node150 *next;
};

// 使用数组模拟栈
int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];
    int top = 0;

    for (int i = 0; i < tokensSize; ++i) {
        if (strlen(tokens[i]) > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) {
            stack[top++] = atoi(tokens[i]);
        } else {
            switch (tokens[i][0]) {
                case '+':
                    stack[top - 2] = stack[top - 1] + stack[top - 2];
                    break;
                case '-':
                    stack[top - 2] = stack[top - 2] - stack[top - 1];
                    break;
                case '*':
                    stack[top - 2] = stack[top - 1] * stack[top - 2];
                    break;
                case '/':
                    stack[top - 2] = stack[top - 2] / stack[top - 1];
                    break;
            }
            top--;
        }
    }

    return stack[top - 1];
}


// 看了一下官方题解，其他语言都是使用栈处理，只有C不是，哈哈哈
int evalRPN2(char **tokens, int tokensSize) {

    struct Node150 *stack = NULL;

    for (int i = 0; i < tokensSize; ++i) {
        struct Node150 *value = (struct Node150 *) malloc(sizeof(struct Node150));
        strcpy(value->value, *(tokens + (tokensSize - i - 1)));
        STACK_PUSH(stack, value);
    }

    struct Node150 *cal = NULL;
    struct Node150 *tmp = NULL;
    int count;

    while (1) {
        STACK_COUNT(stack, tmp, count);
        if (count < 1) {
            break;
        }

        STACK_POP(stack, tmp);
        if (0 == strncmp(tmp->value, "+", sizeof(tmp->value))
            || 0 == strncmp(tmp->value, "-", sizeof(tmp->value))
            || 0 == strncmp(tmp->value, "*", sizeof(tmp->value))
            || 0 == strncmp(tmp->value, "/", sizeof(tmp->value))
                ) {
            struct Node150 *first, *second;
            STACK_POP(cal, first);
            STACK_POP(cal, second);

            int f = atoi(first->value);
            int s = atoi(second->value);

            struct Node150 *new = (struct Node150 *) malloc(sizeof(struct Node150));
            if (0 == strncmp(tmp->value, "+", sizeof(tmp->value))) {
                sprintf(new->value, "%d", f + s);
            } else if (0 == strncmp(tmp->value, "-", sizeof(tmp->value))) {
                sprintf(new->value, "%d", f - s);
            } else if (0 == strncmp(tmp->value, "*", sizeof(tmp->value))) {
                sprintf(new->value, "%d", f * s);
            } else if (0 == strncmp(tmp->value, "/", sizeof(tmp->value))) {
                sprintf(new->value, "%d", s / f);
            }

            STACK_PUSH(stack, new);
        } else {
            STACK_PUSH(cal, tmp);
        }
    }

    STACK_POP(cal, tmp);

    return atoi(tmp->value);
}