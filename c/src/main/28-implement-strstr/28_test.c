#include "28.h"
#include <criterion/criterion.h>

Test(strStr, a001) {
    char *ha[] = {
            "hello",
            "aaaaa",
            "ababab",
            "aaa",
            "mississippi",
            "mississippi",
            "aaaa",

    };

    char *ne[] = {
            "ll",
            "bba",
            "",
            "aaaa",
            "issip",
            "issipi",
            "baaa",
    };

    int expected[] = {
            2,
            -1,
            0,
            -1,
            4,
            -1,
            -1,
    };

    int n = 7;

    for (int i = 0; i < n; ++i) {
        int x = strStr(ha[i], ne[i]);
        cr_assert_eq(x, expected[i], "[%d] %d != %d", i, x, expected[i]);
    }

}