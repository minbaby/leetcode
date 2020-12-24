#include "29.h"

static long a_div(long a, long b) {
    if (a<b) {
        return  0;
    }
    long count = 1;
    long tb = b;
    while (tb+tb <=a) {
        count = count+count;
        tb = tb+tb;
    }

    return count + a_div(a-tb, b);
}

int divide(int dividend, int divisor){
    if (divisor == 0) {
        return 0;
    }

    if (divisor == 1) {
        return dividend;
    }

    if (divisor == -1 ) {
        // 只要不是最小的那个整数，都是直接返回相反数就好啦
        if (dividend > INT_MIN) {
            return -dividend;
        }

        // 是最小的那个，那就返回最大的整数啦
        return INT_MAX;
    }

    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ((a > 0 && b < 0) || (a<0 && b> 0)) {
        sign = -1;
    }

    a = a > 0 ? a: -a;
    b = b > 0 ? b: -b;
    long res = a_div(a, b);
    if (sign > 0) {
        return (int) (res > INT_MAX ? INT_MAX : res);
    }
    return (int) -res;
}