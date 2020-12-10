#include "28.h"

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
