#include "11.h"
#include <criterion/criterion.h>

Test(maxArea, a001) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = 9;
    int expected = 49;

    cr_assert_eq(expected, maxArea(height, heightSize));
}

Test(maxArea, a002) {
    int height[] = {1, 1};
    int heightSize = 2;
    int expected = 1;

    cr_assert_eq(expected, maxArea(height, heightSize));
}

Test(maxArea, a003) {
    int height[] = {4,3,2,1,4};
    int heightSize = 5;
    int expected = 16;

    cr_assert_eq(expected, maxArea(height, heightSize));
}

Test(maxArea, a004) {
    int height[] = {1,2,1};
    int heightSize = 3;
    int expected = 2;

    cr_assert_eq(expected, maxArea(height, heightSize));
}

Test(maxArea, a005) {
    int height[] = {2,3,4,5,18,17,6};
    int heightSize = 7;
    int expected = 17;

    cr_assert_eq(expected, maxArea(height, heightSize));
}