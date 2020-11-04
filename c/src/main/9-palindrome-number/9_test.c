#include "9.h"
#include <criterion/criterion.h>
#include <limits.h>

Test(isPalindrome, a001) {
    int input = 121;
    bool expected = true;
    cr_assert_eq(expected, isPalindrome(input));
}

Test(isPalindrome, a002) {
    int input = -121;
    bool expected = false;
    cr_assert_eq(expected, isPalindrome(input));
}

Test(isPalindrome, a003) {
    int input = 10;
    bool expected = false;
    cr_assert_eq(expected, isPalindrome(input));
}

Test(isPalindrome, a004) {
    int input = INT_MAX;
    bool expected = false;
    cr_assert_eq(expected, isPalindrome(input));
}