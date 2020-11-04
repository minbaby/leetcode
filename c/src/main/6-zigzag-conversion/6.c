#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "6.h"

// 思路：
// 1. 先从上往下，x轴不变，y轴-1
// 2. 当 y轴到达 numRows 时，方向变为从下往上
// 3. 从下往上，x轴+1, y轴+1
// 4. 当 y轴到达 0 时，方向自上往下
// 5. 重复1-4步骤直到结束
char *convert(char *s, int numRows) {
    int len = (int) strlen(s);

    size_t retLen = sizeof(char) * (len + 1);
    char *ret = (char *) malloc(retLen);
    memset(ret, '\0', retLen);

    if (len <= 2 || numRows == 1 || len < numRows) {
        strcpy(ret, s);
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

// 思路2
// 计算出第k个值，属于第几行，之间append进去，然后把各行按照顺序拼接即可
// 周期 n = 2 * rowNums - 2
// 取模 m = k % n
// row = min(m, n-m) += s[k]

// 思路3
// 横扫，直接计算坐标
// 1. 这是一个循环计算， 周期 n = 2*rowNums -2

char * convert2(char * s, int numRows){
    int n = (int) strlen(s);
    if (numRows == 1) return s;
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < n; j++) {
            if (j % (2 * numRows - 2) == i ||
                j % (2 * numRows - 2) == 2 * numRows - 2 - i) {
                res[k] = s[j];
                k++;
            }
        }
    }
    res[k] = '\0';
    return res;
}