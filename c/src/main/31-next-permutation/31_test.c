#include "31.h"
#include <stdio.h>
#include <criterion/criterion.h>

int cccmp(int *a, int *b)
{
    return *a == *b ? 0 : 1;
}

Test(nextPermutation, a001)
{
    cr_skip("todo");
    int args[3] = {3, 2, 1};
    int exptected[3] = {1, 2, 3};

    nextPermutation(args, 3);

    cr_assert_arr_eq_cmp(exptected, args, 3, cccmp);
}

Test(nextPermutation, a002)
{
    cr_skip("todo");
    int args[3] = {1, 3, 2};
    int exptected[3] = {2, 1, 3};

    nextPermutation(args, 3);

    for (size_t i = 0; i < 3; i++)
    {
        printf("%d, ", args[i]);
    }
    

    cr_assert_arr_eq_cmp(exptected, args, 3, cccmp);
}