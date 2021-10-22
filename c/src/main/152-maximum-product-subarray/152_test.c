#include "152.h"
#include <criterion/criterion.h>

Test(t_152_maximum_product_subarray, a001) {
    int input[] = {2, 3, -2, 4};
    int len = sizeof(input) / sizeof(input[0]);

    int expected = 6;

    cr_assert_eq(expected, maxProduct(input, len));
}

Test(t_152_maximum_product_subarray, a002) {
    int input[] = {-2, 0, -1};
    int len = sizeof(input) / sizeof(input[0]);

    int expected = 0;

    cr_assert_eq(expected, maxProduct(input, len));
    cr_assert_eq(expected, maxProduct2(input, len));
}

Test(t_152_maximum_product_subarray, a003) {
    int input[] = {-2};
    int len = sizeof(input) / sizeof(input[0]);

    int expected = -2;

    cr_assert_eq(expected, maxProduct(input, len));
    cr_assert_eq(expected, maxProduct2(input, len));
}

Test(t_152_maximum_product_subarray, a004) {
    int input[] = {-2, 3, -4};
    int len = sizeof(input) / sizeof(input[0]);

    int expected = 24;

    cr_assert_eq(expected, maxProduct(input, len));
    cr_assert_eq(expected, maxProduct2(input, len));
}