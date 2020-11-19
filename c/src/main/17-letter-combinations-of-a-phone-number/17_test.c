#include "17.h"
#include <criterion/criterion.h>

Test(letterCombinations, a001) {
    char *input = "23";
    char *expected[9] = {
            "ad",
            "ae",
            "af",
            "bd",
            "be",
            "bf",
            "cd",
            "ce",
            "cf",
    };

    int *returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;

    char** ret = letterCombinations(input, returnSize);

    for (size_t i = 0; i < *returnSize; i++)
    {
        cr_assert_str_eq(ret[i], expected[i]);
        free(ret[i]);
    }

    free(ret);
    free(returnSize);
}