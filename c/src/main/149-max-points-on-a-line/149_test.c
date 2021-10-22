#include "149.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(t_149_max_points_on_a_line, a001) {
    // "[[0,0]]";
    int **input;
    int d[1][2] = {
            {0, 0},
    };
    int excepted = 1;

    ARRAY_CREATE(input, 1, 2, d);

    int pointsColSize = 2;

    cr_assert_eq(excepted, maxPoints(input, 1, &pointsColSize));
    ARRAY_FREE(input, 1);
}

Test(t_149_max_points_on_a_line, a002) {
    // [[3,3],[1,4],[1,1],[2,1],[2,2]]


    int **input;
    int d[5][2] = {
            {3, 3},
            {1, 4},
            {1, 1},
            {2, 1},
            {2, 2}
    };
    int excepted = 3;

    ARRAY_CREATE(input, 5, 2, d);

    int pointsColSize = 2;

    cr_assert_eq(excepted, maxPoints(input, 5, &pointsColSize));
    ARRAY_FREE(input, 5);
}

Test(t_149_max_points_on_a_line, a003) {
    // [[4,5],[4,-1],[4,0]]

    int **input;
    int d[3][2] = {
            {4, 5},
            {4, -1},
            {4, 0}
    };
    int excepted = 3;

    ARRAY_CREATE(input, 3, 2, d);

    int pointsColSize = 2;

    cr_assert_eq(excepted, maxPoints(input, 3, &pointsColSize));
    ARRAY_FREE(input, 3);
}