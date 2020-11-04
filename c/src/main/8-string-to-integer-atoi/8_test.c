#include "8.h"
#include <criterion/criterion.h>
#include <limits.h>

Test(myAtoi, a001) {
    char *input = "42";
    int expected = 42;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a002) {
    char *input = "   -42";
    int expected = -42;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a003) {
    char *input = "4193 with words";
    int expected = 4193;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a004) {
    char *input = "words and 987";
    int expected = 0;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a005) {
    char *input = "-91283472332";
    int expected = -2147483648;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a006) {
    char *input = "+42";
    int expected = 42;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a007) {
    char *input = "+-42";
    int expected = 0;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a008) {
    char *input = "+++++++++-42";
    int expected = 0;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a009) {
    char *input = "21474836460";
    int expected = 2147483647;

    cr_assert_eq(expected, myAtoi(input));
}

Test(myAtoi, a010) {
    char *input = "  -0012a42";
    int expected = -12;

    cr_assert_eq(expected, myAtoi(input));
}