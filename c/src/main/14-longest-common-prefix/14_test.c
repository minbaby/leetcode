#include "14.h"
#include <criterion/criterion.h>

Test(A, a001)
{
    char *strs[3] = {
        "flower",
        "flow",
        "flight"};
    char *expected = "fl";

    char *x = longestCommonPrefix(strs, 3);

    cr_assert_str_eq(expected, x);

    free(x);
}

Test(A, a002)
{
    char *strs[3] = {
        "dog",
        "racecar",
        "car"};
    char *expected = "";

    char *x = longestCommonPrefix(strs, 3);

    cr_assert_str_eq(expected, x);

    free(x);
}

Test(A, a003)
{
    char *strs[0] = {};
    char *expected = "";

    char *x = longestCommonPrefix(strs, 0);

    cr_assert_str_eq(expected, x);

    free(x);
}