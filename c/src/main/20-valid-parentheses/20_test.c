#include "20.h"
#include <criterion/criterion.h>

Test(isValid, a001) {
    char *str = "()";
    bool expected = true;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a002) {
    char *str = "()[]{}";
    bool expected = true;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a003) {
    char *str = "(]";
    bool expected = false;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a004) {
    char *str = "([)]";
    bool expected = false;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a005) {
    char *str = "{[]}";
    bool expected = true;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a006) {
    char *str = "{";
    bool expected = false;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}

Test(isValid, a007) {
    char *str = "{{";
    bool expected = false;

    cr_assert_eq(expected, isValid(str));
    cr_assert_eq(expected, isValid2(str));
}