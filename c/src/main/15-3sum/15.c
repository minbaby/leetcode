#include "15.h"
#include <stdlib.h>
#include <string.h>

int ccc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 
 * nums 传入参数数组
 * numsSize 传入参数数组长度
 * returnSize 返回的第一维数组大小
 * returnColumnSizes 返回的第一维数组的第二维数组大小
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;

    // 异常情况
    if (numsSize < 3) {
        return NULL;
    }

    // 先对数组进行排序
    qsort(nums, numsSize, sizeof(int), ccc);

    // 初始化返回值
    int **res = (int **) malloc(sizeof(int *) * numsSize * 6);

    int now = 0;
    int low;
    int high;

    while (nums[now] <= 0 && (now + 2) < numsSize) {
        while (now > 0 && (now + 2) < numsSize && nums[now] == nums[now - 1]) {
            now++;
        }

        if ((now + 2) >= numsSize) {
            break;
        }

        low = now + 1;
        high = numsSize - 1;
        int target = -nums[now];

        while (low < high) {
            if (nums[low] + nums[high] == target) {
                res[*returnSize] = (int *) malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[now];
                res[*returnSize][1] = nums[low];
                res[*returnSize][2] = nums[high];
                (*returnSize)++;
                int temp_low = nums[low];
                int temp_high = nums[high];

                while (low < numsSize && nums[low] == temp_low) {
                    low++;
                }

                while (high > now && nums[high] == temp_high) {
                    high--;
                }

                if (high <= low) {
                    break;
                } else {
                    continue;
                }
            }

            if (nums[low] + nums[high] < target) {
                low++;
                continue;
            }

            if (nums[low] + nums[high] > target) {
                high--;
                continue;
            }
        }

        now++;
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return res;
}

