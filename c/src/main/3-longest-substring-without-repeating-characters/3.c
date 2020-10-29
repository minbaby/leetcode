#include "3.h"
#include <stdio.h>
#include <string.h>

#define LEN 128

int lengthOfLongestSubstring(char *s) {
    int hset[LEN];
    int start = 0, count = 0, max = 0;
    memset(hset, -1, sizeof(hset));
    for (int i = 0; i < strlen(s); ++i) {
        if (hset[s[i]] >= start) {
            start = hset[s[i]] + 1;
            count = i - start;
        }
        hset[s[i]] = i;
        count++;
        if (count > max) {
            max = count;
        }
    }


    return max;
}