#include <stdlib.h>
#include <stdio.h>
#include "16-3sum-closest/16.h"

int main(int args, char **arv) {
    int nums[0] = {};
    int numsSize = 1;
    int target = 1;

    int expected = 0;

    int ret = threeSumClosest(nums, numsSize, target);

    printf("%d", ret);
}

