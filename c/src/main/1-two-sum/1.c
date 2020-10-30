#include <stdlib.h>
#include "1.h"

int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    int *_ret = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; ++i) {
        for (int j = numsSize - 1; j >= 0; j--) {
            if (i >= j) {
                break;
            }
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;
                _ret[0] = i;
                _ret[1] = j;
                return _ret;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}