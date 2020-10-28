#include <stdio.h>
#include "../utils.h"
#include "1-two-sum/1.h"

int main(int args, char** arv) {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int *returnSize;

    int expected[] = {0, 1};
    int expectedSize = 2;

    twoSum(nums, numsSize, target, returnSize);

}