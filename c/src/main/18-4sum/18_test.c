#include "18.h"
#include <criterion/criterion.h>

Test(fourSum, a001) {
    cr_skip("fourSum");

    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = 6;
    int target = 0;

    int returnSize = 0;
    int **returnColumnSizes = NULL;

    int **ret = fourSum(nums, numsSize, target, &returnSize, returnColumnSizes);


    free(ret);
}