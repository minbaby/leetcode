#include <string.h>
#include <stdlib.h>
#include "5.h"


int handleX(char *s, int l, int r) {
    int L = l, R = r;
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

char *longestPalindrome(char *s) {
    if (strlen(s) <= 1) {
        return s;
    }

    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); ++i) {
        int is = handleX(s, i, i);
        int id = handleX(s, i, i + 1);

        int len = is >= id ? is : id;
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    char *ret = malloc(sizeof(char) * (end - start + 1));
    strncpy(ret, s + start, end - start + 1);
    return ret;
}
