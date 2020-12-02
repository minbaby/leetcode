#include "16.h"
#include <criterion/criterion.h>

Test(threeSumClosest, a001) {
    int nums[4] = {-1,2,1,-4};
    int numsSize = 4;
    int target = 1;

    int expected = 2;

    int ret = threeSumClosest(nums, numsSize, target);

    cr_assert_eq(ret, expected, "ret:%d expected:%d", ret, expected);
}

Test(threeSumClosest, a002) {
    int nums[0] = {};
    int numsSize = 0;
    int target = 1;

    int expected = 0;

    int ret = threeSumClosest(nums, numsSize, target);

    cr_assert_eq(ret, expected, "ret:%d expected:%d", ret, expected);
}

Test(threeSumClosest, a003) {
    int nums[3] = {0, 1, 2};
    int numsSize = 3;
    int target = 1;

    int expected = 3;

    int ret = threeSumClosest(nums, numsSize, target);

    cr_assert_eq(ret, expected, "ret:%d expected:%d", ret, expected);
}

Test(threeSumClosest, a004) {
    int nums[4] = {0, 2, 1, -3};
    int numsSize = 4;
    int target = 1;

    int expected = 0;

    int ret = threeSumClosest(nums, numsSize, target);

    cr_assert_eq(ret, expected, "ret:%d expected:%d", ret, expected);
}