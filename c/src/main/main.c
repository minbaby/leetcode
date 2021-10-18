#include "149-max-points-on-a-line/149.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>

#define inputSize(x) x
#define inputColSize(x) x

int main(int args, char **arv)
{
    int **input;
    int d[inputSize(3)][inputColSize(2)] = {
            {4, 5},
            {4, -1},
            {4, 0}
    };
    int excepted = 3;

    ARRAY_CREATE(input, inputSize(3), inputColSize(2), d);

    int pointsColSize = 2;

    printf("ret: %d", maxPoints(input, 3, &pointsColSize));
}
