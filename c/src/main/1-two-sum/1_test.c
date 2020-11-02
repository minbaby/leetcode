#include "1.h"
#include <criterion/criterion.h>

Test(TwoSum, a001) {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 0;

    int expected[] = {0, 1};
    int expectedSize = 2;

    int *act = twoSum(nums, numsSize, target, &returnSize);

    cr_assert_arr_eq(act, expected, 2, "error");
    cr_assert_eq(expectedSize, returnSize, "num error");

    free(act);
}

Test(TwoSum, a002) {
    int nums[] = {3, 2, 4};
    int numsSize = 3;
    int target = 6;
    int returnSize = 0;

    int expected[] = {1, 2};
    int expectedSize = 2;

    int *act = twoSum(nums, numsSize, target, &returnSize);

    cr_assert_arr_eq(act, expected, 2, "value error");
    cr_assert_eq(expectedSize, returnSize, "num error");

    free(act);
}