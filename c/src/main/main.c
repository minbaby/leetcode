#include <stdio.h>
#include "4-findMedianSortedArrays/4.h"

int main(int args, char **arv) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = 2;
    int nums2Size = 1;

    double ret = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("%f====", ret);
}