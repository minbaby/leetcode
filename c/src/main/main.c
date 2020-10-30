#include <stdio.h>
#include "3-longest-substring-without-repeating-characters/3.h"

int main(int args, char **arv) {
    char *str = "tmmzuxt";

    int x = lengthOfLongestSubstring(str);
    printf("%d====", x);
}