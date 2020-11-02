#include <criterion/criterion.h>
#include "5.h"

Test(longestPalindrome, a001) {
    char *data = "";
    char *expected = "";
    cr_assert_str_eq(expected, longestPalindrome(data));
}

Test(longestPalindrome, a002) {
    char *data = "a";
    char *expected = "a";
    cr_assert_str_eq(expected, longestPalindrome(data));
}

Test(longestPalindrome, a003) {
    char *data = "babad";
    char *expected = "aba"; // or aba
    cr_assert_str_eq(expected, longestPalindrome(data));
}