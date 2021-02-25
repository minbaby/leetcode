#include "832.h"
#include "../../utils.h"
#include <criterion/criterion.h>

#define inputSize(x) x
#define inputColSize(x) x

Test(flipAndInvertImage, a001) {

    int **input;
    int d[inputSize(3)][inputColSize(3)] = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0},
    };

    ARRAY_CREATE(input, inputSize(3), inputColSize(3), d);

    int expected[inputColSize(3)][inputColSize(3)] = {
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
    };

    int *returnSize = malloc(sizeof(int) * 10);
    int **returnColumnSizes = malloc(sizeof(int) * 100);;

    int tmp = inputColSize(3);
    int **returnData = flipAndInvertImage(input, inputSize(3), &tmp, returnSize, returnColumnSizes);

    for (int i = 0; i < inputSize(3); ++i) {
        for (int j = 0; j < inputColSize(3); ++j) {
            cr_assert_eq(returnData[i][j], expected[i][j], "ret:%d expected:%d", returnData[i][j], expected[i][j]);
        }
    }
}
Test(flipAndInvertImage, a002) {
    int **input;
    int d[inputSize(4)][inputColSize(4)] = {
            {1, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 0},
    };

    ARRAY_CREATE(input, inputSize(4), inputColSize(4), d);

    int expected[inputColSize(4)][inputColSize(4)] = {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0},
    };

    int *returnSize = malloc(sizeof(int) * 10);
    int **returnColumnSizes = malloc(sizeof(int) * 100);;

    int tmp = inputColSize(4);
    int **returnData = flipAndInvertImage(input, inputSize(4), &tmp, returnSize, returnColumnSizes);

    for (int i = 0; i < inputSize(4); ++i) {
        for (int j = 0; j < inputColSize(4); ++j) {
            cr_assert_eq(returnData[i][j], expected[i][j], "ret:%d expected:%d", returnData[i][j], expected[i][j]);
        }
    }
}