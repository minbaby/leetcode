#include <stdio.h>
#include <stdlib.h>
#include "15-3sum/15.h"

int main(int args, char **arv) {
    int nums[6] = {-1, 0, 1, 2, -1, -4};

    int *returnSize = (int *) malloc(sizeof(int *));
    *returnSize = -1;

    int *returnColumnSizes[1] = {};


    int **x = threeSum(nums, 6, returnSize, returnColumnSizes);

    for (int i = 0; i < 2; ++i) {
        printf("%d===", (*(x+i))[0]);
        printf("%d===", (*(x+i))[1]);
        printf("%d===\n", (*(x+i))[2]);
    }

    free(*returnColumnSizes);

    for (int i = 0; i < *returnSize; ++i) {
        free(x[i]);
    }
    free(x);
    free(returnSize);
}