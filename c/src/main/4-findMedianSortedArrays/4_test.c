#include <criterion/criterion.h>
#include "4.h"

Test(findMedianSortedArrays, a001) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = 2;
    int nums2Size = 1;
    double expected = 2.0;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}

Test(findMedianSortedArrays, a002) {
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    int nums1Size = 2;
    int nums2Size = 2;
    double expected = 2.5;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}

Test(findMedianSortedArrays, a003) {
    int nums1[] = {};
    int nums2[] = {1};
    int nums1Size = 0;
    int nums2Size = 1;
    double expected = 1;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}

Test(findMedianSortedArrays, a004) {
    int nums1[] = {0, 0};
    int nums2[] = {0, 0};
    int nums1Size = 0;
    int nums2Size = 0;
    double expected = 0;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}

Test(findMedianSortedArrays, a005) {
    int nums1[] = {2};
    int nums2[] = {};
    int nums1Size = 1;
    int nums2Size = 0;
    double expected = 2;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}

Test(findMedianSortedArrays, a006) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = 2;
    int nums2Size = 1;
    double expected = 2;

    cr_assert_eq(expected, findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}
