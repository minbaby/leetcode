#include "7.h"
#include <limits.h>
#include <criterion/criterion.h>

Test(reverse, 001) {
    int target = 123;
    int expected = 321;

    cr_assert_eq(expected, reverse(target));
}

Test(reverse, 002) {
    int target = -123;
    int expected = -321;

    cr_assert_eq(expected, reverse(target));
}

Test(reverse, 003) {
    int target = 120;
    int expected = 21;

    cr_assert_eq(expected, reverse(target));
}

Test(reverse, 004) {
    int target = INT_MAX;
    int expected = 0;

    cr_assert_eq(expected, reverse(target));
}