#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#ifndef LEET_CODE_832_H
#define LEET_CODE_832_H

//@see https://leetcode-cn.com/problems/flipping-an-image/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **flipAndInvertImage(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes);

void printMatrix(int **A, int ASize, const int *AColSize);

#endif // LEET_CODE_832_H