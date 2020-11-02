#include <criterion/criterion.h>
#include "5.h"

Test(longestPalindrome, a001) {
    char *data = "";
    char *expected = "";

    char *ret = longestPalindrome(data);
    cr_assert_str_eq(expected, ret);
}

Test(longestPalindrome, a002) {
    char *data = "a";
    char *expected = "a";

    char *ret = longestPalindrome(data);
    cr_assert_str_eq(expected, ret);
}

Test(longestPalindrome, a003) {
    char *data = "babad";
    char *expected = "aba"; // or aba

    char *ret = longestPalindrome(data);
    cr_assert_str_eq(expected, ret);
    free(ret);
}