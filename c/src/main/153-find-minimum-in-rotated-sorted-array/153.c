#include "153.h"

/**
*  时间复杂度为 O(N)
 *  空间复杂度为 O(1)
 *
 * @param nums
 * @param numsSize
 * @return
 */
int findMin(int *nums, int numsSize) {
    int l = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i - 1] > nums[i]) {
            l = i;
            break;
        }

    }
    return nums[l];
}


/**
 * 二分法
 *  空间复杂度为 O(1)
 *  时间复杂度为 O(N*log(n))
 *
 * @param nums
 * @param numsSize
 * @return
 */
int findMin2(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }

    }

    return nums[left];
}