#include "6.h"
#include "criterion/criterion.h"

Test(zigzag_conversion, a001) {
    char *s = "LEETCODEISHIRING";
    int numRows = 3;
    char *o = "LCIRETOESIIGEDHN";

    char *ret = convert(s, numRows);
    cr_assert_str_eq(o, ret);
    free(ret);
}

Test(zigzag_conversion, a002) {
    char *s = "LEETCODEISHIRING";
    int numRows = 4;
    char *o = "LDREOEIIECIHNTSG";

    char *ret = convert(s, numRows);
    cr_assert_str_eq(o, ret);
    free(ret);
}