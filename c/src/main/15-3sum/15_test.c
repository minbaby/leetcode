#include "15.h"
#include <criterion/criterion.h>

Test(threeSum, a001) {
    int nums[6] = {-1, 0, 1, 2, -1, -4};

    int *returnSize = (int *) malloc(sizeof(int *));
    *returnSize = -1;

    int expectedReturnSize = 2;
    char expectedReturn[2][3] = {
            {-1, -1, 2},
            {-1, 0,  1},
    };

    int *returnColumnSizes[1] = {};

    int **x = threeSum(nums, 6, returnSize, returnColumnSizes);

    cr_assert_eq(*returnSize, expectedReturnSize);

    for (int i = 0; i < expectedReturnSize; ++i) {
        cr_assert(expectedReturn[i][0] == (*(x + i))[0]);
        cr_assert(expectedReturn[i][1] == (*(x + i))[1]);
        cr_assert(expectedReturn[i][2] == (*(x + i))[2]);
    }

    free(returnColumnSizes[0]);

    for (int i = 0; i < *returnSize; ++i) {
        free(x[i]);
    }
    free(x);
    free(returnSize);
}

Test(threeSum, a002) {
    int nums[11] = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};

    int *returnSize = (int *) malloc(sizeof(int *));
    *returnSize = -1;

    int expectedReturnSize = 9;
    char expectedReturn[9][3] = {
            {-4,0,4},
            {-4,1,3},
            {-3,-1,4},
            {-3,0,3},
            {-3,1,2},
            {-2,-1,3},
            {-2,0,2},
            {-1,-1,2},
            {-1,0,1}
    };

    int *returnColumnSizes[1] = {};

    int **x = threeSum(nums, 11, returnSize, returnColumnSizes);

    cr_assert_eq(*returnSize, expectedReturnSize);

    for (int i = 0; i < expectedReturnSize; ++i) {
        cr_assert(expectedReturn[i][0] == (*(x + i))[0]);
        cr_assert(expectedReturn[i][1] == (*(x + i))[1]);
        cr_assert(expectedReturn[i][2] == (*(x + i))[2]);
    }

    free(returnColumnSizes[0]);

    for (int i = 0; i < *returnSize; ++i) {
        free(x[i]);
    }
    free(x);
    free(returnSize);
}