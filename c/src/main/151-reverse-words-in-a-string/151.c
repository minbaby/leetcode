#include "151.h"

// 如果使用其他语言， 基本就是 trim，split，join 完事
// C语言 利用栈，从后向前遍历字符串，将单词压入栈，遇到空格则将栈中单词取出。
char *reverseWords(char *s) {
    int strLen = (int) strlen(s);
    int sizeOf = (strlen(s) + 1) * sizeof(char);

    char *stack = (char *) malloc(sizeOf);
    memset(stack, '\0', sizeOf);

    char *ret = (char *) malloc(sizeOf);
    memset(ret, '\0', sizeOf);

    // swap
    for (int i = 0; i < strLen; ++i) {
        stack[strLen - i - 1] = s[i];
    }

    // trim space
    char last = ' ';
    int top = 0;
    for (int i = 0; i < strLen; ++i) {
        if (last == ' ' && stack[i] == ' ') {
            continue;
        }

        ret[top++] = stack[i];
        last = stack[i];
    }

    // trim last
    for (int i = (int) strlen(ret) - 1; i >= 0; i--) {
        if (ret[i] == ' ') {
            ret[i] = '\0';
        } else {
            break;
        }
    }

    //reverse world
    int start = -1;
    for (int i = 0; i <= strlen(ret); ++i) {
        if (start == -1 && ret[i] != ' ') {
            start = i;
        } else if (start != -1 && (ret[i] == ' ' || ret[i] == '\0')) {
            //swap, start
            int _l = (i - start) / 2;
            for (int j = start; j <= start + _l - 1; ++j) {
                char tmp = ret[j];
                ret[j] = ret[i - j + start - 1];
                ret[i - j + start - 1] = tmp;
            }
            start = -1;
        }
    }

    free(stack);
    return ret;
}

