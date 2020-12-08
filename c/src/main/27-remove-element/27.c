#include "27.h"

int removeElement(int *nums, int numsSize, int val) {
    int l = 0, r = 0;
    while (r < numsSize & l < numsSize && l <= r) {
        if (nums[r] != val) {
            nums[l++] = nums[r];
        }
        r++;
    }

    return l;
}