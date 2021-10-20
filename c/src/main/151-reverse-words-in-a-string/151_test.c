#include "151.h"
#include <criterion/criterion.h>

Test(t_151_reverse_words_in_a_string, a001) {
    char *input = "        the              sky         is blue       ";
    char *expected = "blue is sky the";

    char *x = reverseWords(input);
    cr_assert_str_eq(x, expected);
}

Test(t_151_reverse_words_in_a_string, a002) {
    char *input = "  hello world  ";
    char *expected = "world hello";

    char *x = reverseWords(input);
    cr_assert_str_eq(x, expected);
}

Test(t_151_reverse_words_in_a_string, a003) {
    char *input = "a good   example";
    char *expected = "example good a";

    char *x = reverseWords(input);
    cr_assert_str_eq(x, expected);
}

Test(t_151_reverse_words_in_a_string, a004) {
    char *input = "";
    char *expected = "";

    char *x = reverseWords(input);
    cr_assert_str_eq(x, expected);
}