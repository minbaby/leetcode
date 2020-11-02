#include "3.h"
#include <string.h>

#define LEN 128

int lengthOfLongestSubstring(char *s) {
    int max = 0;
    int hash[LEN];
    memset(hash, -1, sizeof(hash));

    int p_head = 0;
    int p_tail = 0;
    int _l;
    int v;

    while (s[p_tail] != '\0') {
        int index = (int) s[p_tail];
        if ((v = hash[index]) != -1) {
            // 发生了重复
            if (max < (_l = p_tail - p_head)) {
                max = _l;
            }

            for (int i = p_head; i <= v; ++i) {
                hash[s[i]] = -1;
            }

            p_head = v + 1;
        }
        hash[index] = p_tail;
        p_tail++;
    }

    if (max < (_l = p_tail - p_head)) {
        max = _l;
    }
    return max;
}

//int lengthOfLongestSubstring(char *s) {
//    int hset[LEN];
//    memset(hset, -1, sizeof(hset));
//
//    int start = 0, count = 0, max = 0;
//    for (int i = 0; i < strlen(s); ++i) {
//        if (hset[s[i]] >= start) {
//            start = hset[s[i]] + 1;
//            count = i - start;
//        }
//        hset[s[i]] = i;
//        count++;
//        if (count > max) {
//            max = count;
//        }
//    }
//
//    return max;
//}