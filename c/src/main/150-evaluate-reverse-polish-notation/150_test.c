#include "150.h"
#include <criterion/criterion.h>

Test(t_150_evaluate_reverse_polish_notation, a001) {
    char *input[] = {
            "2",
            "1",
            "+",
            "3",
            "*"
    };
    int excepted = 9;
    int tokenSize = 5;

    cr_assert_eq(excepted, evalRPN(input, tokenSize));
}

Test(t_150_evaluate_reverse_polish_notation, a002) {
    char *input[] = {"4", "13", "5", "/", "+"};
    int excepted = 6;
    int tokenSize = 5;

    cr_assert_eq(excepted, evalRPN(input, tokenSize));
}

Test(t_150_evaluate_reverse_polish_notation, a003) {
    char *input[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int excepted = 22;
    int tokenSize = 13;

    cr_assert_eq(excepted, evalRPN(input, tokenSize));
}