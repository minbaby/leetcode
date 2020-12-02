#include "31.h"
#include <stdlib.h>
#include <stdio.h>

void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 2;
    int j = numsSize - 1;
    while (i >= 0 && nums[i] > nums[j])
    {
        j--;
        i--;
    }
    if (i >= 0)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    for (size_t x = i; x < numsSize; x++)
    {
    }

    // for (size_t i = 0; i < numsSize / 2; i++)
    // {
    //     int tmp = nums[i];
    //     nums[i] = nums[numsSize - 1 - i];
    //     nums[numsSize - 1 - i] = tmp;
    // }
}