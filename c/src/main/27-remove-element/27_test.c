#include "27.h"
#include <criterion/criterion.h>

Test(removeElement, a001) {
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int num = 8;
    int num2 = 2;

    int expectedNum = 5;
    int expectedArr[] = {0, 1, 3, 0, 4};

    int x = removeElement(nums, num, num2);

    cr_assert_eq(x, expectedNum);

    for (int i = 0; i < x; ++i) {
        cr_assert_eq(nums[i], expectedArr[i]);
    }
}