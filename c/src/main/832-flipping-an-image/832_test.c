#include "832.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(flipAndInvertImage, a001) {

    int **input;
    int d[3][3] = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0},
    };

    ARRAY_CREATE(input, 3, 3, d);

    int expected[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
    };

    int *returnSize = (int*) malloc(sizeof(int) * 10);
    int **returnColumnSizes = (int **) malloc(sizeof(int) * 100);;

    int tmp = 3;
    int **returnData = flipAndInvertImage(input, 3, &tmp, returnSize, returnColumnSizes);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cr_assert_eq(returnData[i][j], expected[i][j], "ret:%d expected:%d", returnData[i][j], expected[i][j]);
        }
    }
    ARRAY_FREE(input, 3);
    free(returnSize);
    free(returnColumnSizes);
}
Test(flipAndInvertImage, a002) {
    int **input;
    int d[4][4] = {
            {1, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 0},
    };

    ARRAY_CREATE(input, 4, 4, d);

    int expected[4][4] = {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0},
    };

    int *returnSize = malloc(sizeof(int) * 10);
    int **returnColumnSizes = malloc(sizeof(int) * 100);;

    int tmp = 4;
    int **returnData = flipAndInvertImage(input, 4, &tmp, returnSize, returnColumnSizes);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cr_assert_eq(returnData[i][j], expected[i][j], "ret:%d expected:%d", returnData[i][j], expected[i][j]);
        }
    }
    ARRAY_FREE(input, 4);
    free(returnSize);
    free(returnColumnSizes);
}