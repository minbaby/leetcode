#include <criterion/criterion.h>
#include "3.h"

Test(lengthOfLongestSubstring, a001) {
    char *str = "abcabcbb";
    int expected = 3;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a002) {
    char *str = "bbbbb";
    int expected = 1;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a003) {
    char *str = "pwwkew";
    int expected = 3;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a004) {
    char *str = "";
    int expected = 0;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a005) {
    char *str = " ";
    int expected = 1;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a006) {
    char *str = "tmmzuxt";
    int expected = 5;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a007) {
    char *str = "dvdf";
    int expected = 3;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}

Test(lengthOfLongestSubstring, a008) {
    char *str = "ohvhjdml";
    int expected = 6;

    cr_assert_eq(expected, lengthOfLongestSubstring(str));
}