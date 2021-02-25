#include "29-divide-two-integers/29.h"
#include "832-flipping-an-image/832.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>


void point_point() {
    int **data = malloc(sizeof(int) * 6);

    int *line1 = malloc(sizeof(int) * 3);
    *line1 = 1;
    *(line1 + 1) = 2;
    *(line1 + 2) = 3;

    int *line2 = malloc(sizeof(int) * 3);
    line2[0] = 4;
    line2[1] = 5;
    line2[2] = 6;

    *data = line1;
    *(data + 1) = line2;


    printf("%d\n", data[0][0]);
    printf("%d\n", data[0][1]);
    printf("%d\n", data[1][0]);
}

int main(int args, char **arv) {

    int **data;
    int d[3][3] = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0},
    };
    ARRAY_CREATE(data, 3, 3, d);


    int inputSize = 3;
    int inputColSize = 3;

    int expected[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
    };
    int expectedSize = 3;

    int *returnSize = malloc(sizeof(int) * 100);
    int **returnColumnSizes = malloc(sizeof(int) * 1000);;

    int **returnData = flipAndInvertImage(data, inputSize, &inputColSize, returnSize, returnColumnSizes);
    printMatrix(returnData, inputSize, &inputColSize);
}



