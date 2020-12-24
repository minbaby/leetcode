#include "29.h"
#include <criterion/criterion.h>

Test(divide, a001) {
    int dividend = 10;
    int divisor = 3;
    int expected = 3;

    cr_assert_eq(expected, divide(dividend, divisor));
}
Test(divide, a002) {
    int dividend = 7;
    int divisor = -3;
    int expected = -2;

    cr_assert_eq(expected, divide(dividend, divisor));
}