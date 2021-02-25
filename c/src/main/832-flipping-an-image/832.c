#include "832.h"

int **flipAndInvertImage(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = ASize;
    *returnColumnSizes = AColSize;

    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < *AColSize / 2; ++j) {
            int tmp = A[i][*AColSize - j - 1];
            A[i][*AColSize - j - 1] = A[i][j];
            A[i][j] = tmp;
        }
    }

    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < *AColSize; ++j) {
            A[i][j] ^= 1;
        }
    }

    return A;
}

void printMatrix(int **A, int ASize, const int *AColSize) {
    printf("==========\n");
    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < *AColSize; ++j) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("==========");
}
