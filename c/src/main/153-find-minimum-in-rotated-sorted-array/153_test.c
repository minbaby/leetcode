#include "153.h"
#include <criterion/criterion.h>

Test(t_153_find_minimum_in_rotated_sorted_array, a001) {
    int nums[] = {3, 4, 5, 1, 2};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int excepted = 1;

    cr_assert_eq(findMin(nums, numSize), excepted);
}

Test(t_153_find_minimum_in_rotated_sorted_array, a002) {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int excepted = 0;

    cr_assert_eq(findMin(nums, numSize), excepted);
}

Test(t_153_find_minimum_in_rotated_sorted_array, a003) {
    int nums[] = {2, 1};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int excepted = 1;

    cr_assert_eq(findMin(nums, numSize), excepted);
}