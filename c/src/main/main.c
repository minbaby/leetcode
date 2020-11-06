#include <stdio.h>
#include "11-container-with-most-water/11.h"

int main(int args, char **arv) {
    int height[] = {2,3,4,5,18,17,6};
    int heightSize = 7;
    int expected = 17;

    printf("%d#####\n", maxArea(height, heightSize));
}