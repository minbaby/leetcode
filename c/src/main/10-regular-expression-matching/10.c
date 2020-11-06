#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "10.h"

bool isMatch(char *s, char *p) {
    size_t sLen = strlen(s);
//    if (sLen > 20 || sLen == 0) {
//        return false;
//    }

    size_t pLen = strlen(p);
//    if (pLen > 30 || pLen == 0) {
//        return false;
//    }

    int dp[sLen + 1][pLen + 1];
    memset(dp, -1, sizeof(dp));

    dp[0][0] = true;
    for (int j = 1; j < pLen + 1; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    return false;
}