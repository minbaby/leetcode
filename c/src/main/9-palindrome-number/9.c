#include "9.h"
#include <stdlib.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long n = 0;
    int tmp = x;

    while (tmp) {
        n = n * 10 + tmp % 10;
        tmp /= 10;
    }


    return (int) n == x;
}