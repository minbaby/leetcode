#include <stdio.h>
#include <stdlib.h>
#include "16-3sum-closest/16.h"

int main(int args, char **arv) {
    int nums[4] = {0, 2, 1, -3};
    int numsSize = 4;
    int target = 1;

    int ret = threeSumClosest(nums, numsSize, target);
    printf("%d---", ret);
}