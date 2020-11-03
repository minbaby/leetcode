#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "6.h"

// 这个有个问题： 返回的 char*, 有的需要free 有的不需要，暂时还不知道有什么好方法来搞，暂时先放着把。
char *convert(char *s, int numRows) {
    int len = (int) strlen(s);

    if (len <= 2 || numRows == 1 || len < numRows) {
        return s;
    }

    int data[numRows][len];
    memset(data, -1, sizeof(data));

    int i = 0, j = 0, k = 0, goingDown = 1;
    while (k < len) {
        data[i][j] = (int) s[k];
        if (goingDown == 1) {
            i++;
            if (i == numRows - 1) {
                goingDown = 0;
            }
        } else {
            i--;
            j++;
            if (i == 0) {
                goingDown = 1;
            }
        }
        k++;
    }


    size_t retLen = sizeof(char) * (len + 1);
    char *ret = (char *) malloc(retLen);
    memset(ret, '\0', retLen);

    k = 0;
    for (int l = 0; l < numRows; ++l) {
        for (int m = 0; m < len; ++m) {
            if (data[l][m] == -1) {
                continue;
            }

            ret[k] = (char) data[l][m];
            k++;
        }
    }

    return ret;
}