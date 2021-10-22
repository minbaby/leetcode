#include "152.h"
#include "../../utils.h"

/**
 *  取值范围为 正数，即 正整数，负整数，0，
 *  也就是 累乘，其绝对值，只可能是0，或者增大，也就是乘的数字越多，值越大或者越小
 *
 * @param nums
 * @param numsSize
 * @return
 */
int maxProduct(int *nums, int numsSize) {
    int *maxF = (int *) malloc(numsSize * sizeof(int));
    memset(maxF, 0, numsSize * sizeof(int));
    maxF[0] = nums[0];

    int *minF = (int *) malloc(numsSize * sizeof(int));
    memset(minF, 0, numsSize * sizeof(int));
    minF[0] = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        int _max = maxF[i - 1] * nums[i];
        int _min = minF[i - 1] * nums[i];

        maxF[i] = MAX(_max, MAX(_min, nums[i]));
        minF[i] = MIN(_max , MIN(_min , nums[i]));
    }

    int ret = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        ret = MAX(ret, maxF[i]);
    }

    free(minF);
    free(maxF);

    return ret;
}

int maxProduct2(int *nums, int numsSize) {
    int maxF = nums[0];
    int minF = nums[0];
    int max = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        int _max = maxF * nums[i];
        int _min = minF * nums[i];

        maxF = MAX(_max, MAX(_min, nums[i]));
        minF = MIN(_max , MIN(_min , nums[i]));
        max = MAX(max, maxF);
    }

    return max;
}
