#include "11.h"

// 设 左右指针分别为 x,y, 距离为 t, 则此时面积为 m = t * min (x, y)
// 设 x > y
// 初始面积 m1 = t * y
// 若左指针右移面积 m2 = (t-1) * min(?, y) 此时最大面积为 m21 = (t-1) * y
// 若右指针左移面积 m3 = (t-1) * min(x, ?) 此时最大面积为 m31 = (t-1) * x
// 
//  则有 m1 > m21 
//  m1 和 m31 面积不确定， 可能变大也可能变小
//  所以只能往不确定的方向移动，即 数字小的指针进行移动
int maxArea(int *height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;

    int maxNums = 0;
    int m;
    while (i <= j) {
        if (height[i] < height[j]) {
            m = (j - i) * height[i];
            i++;
        } else {
            m = (j - i) * height[j];
            j--;
        }
        maxNums = maxNums > m ? maxNums : m;
    }

    return maxNums;
}
