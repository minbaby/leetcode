#include "10.h"
#include <criterion/criterion.h>

Test(isMatch, a001) {
    char *input = "aa";
    char *p = "a";
    bool expected = false;


    criterion_skip_test("有点难度");
    cr_assert_eq(isMatch(input, p), expected);
}

Test(isMatch, a002) {
    char *input = "aa";
    char *p = "a*";
    bool expected = true;

    criterion_skip_test("有点难度");
    cr_assert_eq(isMatch(input, p), expected);
}

Test(isMatch, a003) {
    char *input = "ab";
    char *p = ".*";
    bool expected = true;

    criterion_skip_test("有点难度");
    cr_assert_eq(isMatch(input, p), expected);
}

Test(isMatch, a004) {
    char *input = "aab";
    char *p = "c*a*b";
    bool expected = true;

    criterion_skip_test("有点难度");
    cr_assert_eq(isMatch(input, p), expected);
}

Test(isMatch, a005) {
    char *input = "mississippi";
    char *p = "mis*is*p*.";
    bool expected = false;

    criterion_skip_test("有点难度");
    cr_assert_eq(isMatch(input, p), expected);
}
