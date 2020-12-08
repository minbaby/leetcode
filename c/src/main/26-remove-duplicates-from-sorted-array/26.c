#include "26.h"

int has(const int *c, int num, int d, const int *nums) {
    for (int i = 0; i < num; ++i) {
        if (nums[c[i]] == nums[d]) {
            return 1;
        }
    }

    return 0;
}

// 使用了额外的存储空间
int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int *c = malloc(sizeof(int) * numsSize);
    memset(c, -1, sizeof(int) * numsSize);
    int ci = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (has(c, ci, i, nums)) {
            continue;
        }

        c[ci++] = i;
    }

    for (int i = 0; i < ci; ++i) {
        nums[i] = nums[c[i]];
    }

    free(c);

    return ci;
}

int removeDuplicates2(int *nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int l = 0, r = 0;
    while (l <= r && r < numsSize && l < numsSize) {
        if (nums[l] == nums[r]) {
            r++;
        } else {
            nums[++l] = nums[r];
        }
    }

    return l+1;
}