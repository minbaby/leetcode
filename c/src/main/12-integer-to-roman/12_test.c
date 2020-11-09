#include <criterion/criterion.h>
#include "12.h"
#include <stdlib.h>

Test(intToRoman, a001) {
    int input = 3;
    char *x = "III";

    char *actual = intToRoman(input);

    cr_assert_str_eq(x, actual);

    free(actual);
}

Test(intToRoman, a002) {
    int input = 4;
    char *x = "IV";

    char *actual = intToRoman(input);

    cr_assert_str_eq(x, actual);

    free(actual);
}

Test(intToRoman, a003) {
    int input = 9;
    char *x = "IX";

    char *actual = intToRoman(input);

    cr_assert_str_eq(x, actual);

    free(actual);
}

Test(intToRoman, a004) {
    int input = 58;
    char *x = "LVIII";

    char *actual = intToRoman(input);

    cr_assert_str_eq(x, actual);

    free(actual);
}

Test(intToRoman, a005) {
    int input = 1994;
    char *x = "MCMXCIV";

    char *actual = intToRoman(input);

    cr_assert_str_eq(x, actual);

    free(actual);
}