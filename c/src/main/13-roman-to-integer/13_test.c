#include "13.h"
#include <criterion/criterion.h>

Test(romanToInt, a001) {
    char *target = "III";
    int excpeted = 3;

    int actual = romanToInt(target);
    cr_assert_eq(actual, excpeted);
}

Test(romanToInt, a002) {
    char *target = "MCMXCIV";
    int excpeted = 1994;

    int actual = romanToInt(target);
    cr_assert_eq(actual, excpeted);
}

Test(romanToInt, a003) {
        char *target = "DCXXI";
    int excpeted = 621;

    int actual = romanToInt(target);
    cr_assert_eq(actual, excpeted);
}