#include <stdio.h>
#include "../utils.h"
#include "153-find-minimum-in-rotated-sorted-array/153.h"

int main(int args, char **arv) {
//    int nums[] = {3,4,5,1,2};
//    int nums[] = {4,5,6,7,0,1,2};
//    int nums[] = {11, 13, 15, 17};
    int nums[] = {2,1};
    int numSize = sizeof(nums) / sizeof(nums[0]);

    int n = findMin2(nums, numSize);

    printf("\n%d=", n);
}
