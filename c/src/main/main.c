#include <stdio.h>
#include "../utils.h"
#include "152-maximum-product-subarray/152.h"

int main(int args, char **arv) {
    int nums[] = {-2, 3, -4};
    int numSize = sizeof(nums) / sizeof(nums[0]);

    int n = maxProduct2(nums, numSize);

    printf("%d=", n);
}
