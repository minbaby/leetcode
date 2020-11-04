#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "6.h"

char *convert(char *s, int numRows) {
    int len = (int) strlen(s);

    size_t retLen = sizeof(char) * (len + 1);
    char *ret = (char *) malloc(retLen);
    memset(ret, '\0', retLen);

    if (len <= 2 || numRows == 1 || len < numRows) {
        for (int i = 0; i < len; ++i) {
            ret[i] = s[i];
        }

        return ret;
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