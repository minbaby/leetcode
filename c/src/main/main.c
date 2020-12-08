#include "27-remove-element/27.h"
#include <stdlib.h>
#include <stdio.h>

int main(int args, char **arv) {
    int nums[] = {0,1,2,2,3,0,4,2};
    int num = 8;
    int num2 = 2;
    int x = removeElement(nums, num, num2);
    printf("%d", x);
}

