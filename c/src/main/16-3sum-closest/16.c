#include "16.h"
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int threeSumClosest(int *nums, int numsSize, int target) {
    if (numsSize < 3) {
        return 0;
    }

    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int diff = INT_MAX;
    int ret = 0;
    int sum;
    int l;
    int r;

    for (int i = 0; i < numsSize - 2; ++i) {
        l = i + 1;
        r = numsSize - 1;

        while (l < r) {
            sum = nums[l] + nums[r] + nums[i];

            if (sum == target) {
                return target;
            }

            int d;
            if (sum > target) {
                d = sum - target;
                r--;
            }

            if (sum < target) {
                d = target - sum;
                l++;
            }

            if (d < diff) {
                diff = d;
                ret = sum;
            }
        }
    }

    return ret;
}