#include "26.h"
#include <criterion/criterion.h>

Test(removeDuplicates, a001) {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int num = 10;

    int expectedNum = 5;
    int expectedArr[] = {0, 1, 2, 3, 4};

    int x = removeDuplicates(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}
Test(removeDuplicates, a0012) {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int num = 10;

    int expectedNum = 5;
    int expectedArr[] = {0, 1, 2, 3, 4};

    int x = removeDuplicates2(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}

Test(removeDuplicates, a002) {
    int nums[] = {};
    int num = 0;

    int expectedNum = 0;
    int expectedArr[] = {};

    int x = removeDuplicates(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}

Test(removeDuplicates, a0022) {
    int nums[] = {};
    int num = 0;

    int expectedNum = 0;
    int expectedArr[] = {};

    int x = removeDuplicates2(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}

Test(removeDuplicates, a003) {
    int nums[] = {1,2};
    int num = 2;

    int expectedNum = 2;
    int expectedArr[] = {1,2};

    int x = removeDuplicates(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}

Test(removeDuplicates, a0032) {
    int nums[] = {1,2};
    int num = 2;

    int expectedNum = 2;
    int expectedArr[] = {1,2};

    int x = removeDuplicates2(nums, num);

    cr_assert_eq(x, expectedNum);
    for (int i = 0; i < expectedNum; ++i) {
        cr_assert_eq(expectedArr[i], nums[i]);
    }
}