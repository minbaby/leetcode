#include "149.h"
#include "uthash.h"
#include <math.h>

struct HashTable {
    int key;
    int value;
    UT_hash_handle hh;
};

// 最大公约数：辗转相除（欧几里得算法）
// @see https://zhuanlan.zhihu.com/p/31824895
// @see https://zh.wikipedia.org/zh-cn/%E8%BC%BE%E8%BD%89%E7%9B%B8%E9%99%A4%E6%B3%95
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 252 = 21 * 12
// 105 = 21 * 5
// 252 − 105 = 21 × (12 − 5) = 147 = 21 * 7
int gcd2(int a, int b) {
    if (a == 0) {
        return b;
    }

    while (b != 0) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}


int _max(int a, int b) {
    return a > b ? a : b;
}

// 核心还是斜率计算
// @see https://leetcode-cn.com/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-le-tq8f/
// 问题1，斜率是除出来的，所以一定是小数，但是计算机中的浮点数类型可能因为精度不够而无法足够精确地表示每一个斜率，（解决方案：使用二元组 (x,y)，表示分子和分母）
// 问题2，分子和分母，可能有可以约分的情况（取最大公约数）
// 问题3，可能出现商一样，但是，分子和分母，正负相反的情况 （约定，y 必须为正数）
// 问题4，分子或者分母，可能出现为 0 的情况，这时x,y 没有数学意义上的最大公约数（约定，当x=0时，y=1， 当 x=1时，y=0）
//
// 优化1，当点数不多于2当时候，可以直接返回总点数
// 优化2，当我们枚举到点 i 时，我们只考虑 ~编号~ 大于 i 的点到点 i 的斜率，因为，如果直线同时经过编号小于 i 的点j，当我们枚举 j 时已经处理过该直线了。(编号，暂时还不清楚定义）
// 优化3，当一条直线经过的点数，超过了总点数的半数，则我们可以确定该直线为经过最多点的直线
// 优化4，当我们枚举到点 i 时，我们至多只能再找到 n−i 个点共线。假设此时找到点共线点数量最大值为k，如果 k >= n-i，那么此时我们即可以停止枚举，因为不可能再找到更大点答案了
int maxPoints(int **points, int pointsSize, int *pointsColSize) {
    int n = pointsSize;
    if (n <= 2) {
        return n;
    }

    int ret = 0;
    // 一点 i 到 大于 i 的所有点的所有直线
    for (int i = 0; i < n; ++i) {
        if (ret > n / 2 /* 优化3 */ || ret >= n - i /* 优化4 */) {
            break;
        }

        struct HashTable *hashTable = NULL;
        for (int j = i + 1; j < n; ++j) {
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            if (x == 0) {
                y = 1;
            } else if (y == 0) {
                x = 1;
            } else {
                if (y < 0) {
                    x = -x;
                    y = -y;
                }
                int gcdXY = gcd(abs(x), abs(y));
                x /= gcdXY;
                y /= gcdXY;
            }

            struct HashTable *tmp;
            int val = y + x * 20010; // 元组转int， 也可以使用字符串，转换成唯一值即可
            HASH_FIND_INT(hashTable, &val, tmp);
            if (tmp == NULL) {
                tmp = (struct HashTable *) malloc(sizeof(struct HashTable));
                tmp->key = val;
                tmp->value = 1;
                HASH_ADD_INT(hashTable, key, tmp);
            } else {
                tmp->value++;
            }
        }

        int maxN = 0;
        struct HashTable *iter, *tmp;
        HASH_ITER(hh, hashTable, iter, tmp) {
            maxN =  _max(maxN, iter->value + 1);
            HASH_DEL(hashTable, iter);
            free(iter);
        }
        ret =  _max(ret, maxN);
    }

    return ret;
}