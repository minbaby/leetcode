#include "28.h"

// 暴力破解
int strStr(char *haystack, char *needle) {
    if (strlen(needle) == 0) {
        return 0;
    }

    if (strlen(needle) > strlen(haystack)) {
        return -1;
    }

    int ph = 0;
    int pn = 0;
    int start = 0;
    while (1) {
        if (ph >= strlen(haystack) || pn >= strlen(needle)) {
            break;
        }

        if (haystack[ph] != needle[pn]) {
            if (start == 1) {
                start = 0;
                ph = ph - pn + 1;
                pn = 0;
                continue;
            }
            ph++;
        } else {
            start = 1;
            pn++;
            ph++;
        }
    }

    if (start == 1 && pn == strlen(needle)) {
        // 匹配到了
        return ph - pn;
    } else {
        // 没有匹配
        return -1;
    }
}

static void getNext(int next[], const char *s) {
    int j = -1;
    next[0] = j;

    // 注意i从1开始
    for (int i = 1; i < strlen(s); ++i) {
        // 前后缀不相同了
        while (j >= 0 && s[i] != s[j + 1]) {
            // 向前回溯
            j = next[j];
        }

        // 找到相同的前后缀
        if (s[i] == s[j + 1]) {
            j++;
        }

        // 将j（前缀的长度）赋给next[i]
        next[i] = j;
    }
}

// kmp算法学习
int strStr2(char *haystack, char *needle) {
    if (strlen(needle) == 0) {
        return 0;
    }

    int next[strlen(needle)];
    memset(next, 0, strlen(needle));
    getNext(next, needle);

    // 因为next数组里记录的起始位置为-1
    int j = -1;
    for (int i = 0; i < strlen(haystack); ++i) {
        // 不匹配
        while (j >= 0 && haystack[i] != needle[j + 1]) {
            // j 寻找之前匹配的位置
            j = next[j];
        }

        // 匹配，j和i同时向后移动
        if (haystack[i] == needle[j + 1]) {
            j++;
        }

        // 文本串s里出现了模式串t
        if (j == (strlen(needle) - 1)) {
            return (int) (i - strlen(needle) + 1);
        }
    }


    return -1;
}