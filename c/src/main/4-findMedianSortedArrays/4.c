#include "4.h"
#include <string.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int sum = nums2Size + nums1Size;
    if (sum == 0) {
        return 0;
    }

    if (sum == 1) {
        if (nums1Size == 1) {
            return nums1[0];
        }
        if (nums2Size == 1) {
            return nums2[0];
        }
    }

    int ret[sum];
    memset(ret, 0, sizeof(ret));

    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (p1 < nums1Size && p2 < nums2Size) {
        if (nums1[p1] < nums2[p2]) {
            ret[i] = nums1[p1];
            p1++;
        } else {
            ret[i] = nums2[p2];
            p2++;
        }
        i++;
    }

    while (p1 < nums1Size) {
        ret[i] = nums1[p1];
        p1++;
        i++;
    }

    while (p2 < nums2Size) {
        ret[i] = nums2[p2];
        p2++;
        i++;
    }

    int mid = sum / 2;
    return sum % 2 ? ret[mid] : (ret[mid] + ret[mid - 1]) / 2.0;
}