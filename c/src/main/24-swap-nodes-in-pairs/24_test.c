#include "24.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(swapPairs, a001) {
    int d1[] = {1, 2, 3, 4};
    struct ListNode * l1 = utils_list_create(d1, 4);

    int d2[] = {2, 1, 4, 3};
    struct ListNode * l2 = utils_list_create(d2, 4);

    struct ListNode *ret = swapPairs(l1);

    cr_assert(utils_list_cmp(l2, ret));

    utils_list_free(ret);
    utils_list_free(l2);
}

Test(swapPairs, a002) {
    int d1[] = {1};
    struct ListNode * l1 = utils_list_create(d1, 1);

    int d2[] = {1};
    struct ListNode * l2 = utils_list_create(d2, 1);

    struct ListNode *ret = swapPairs(l1);

    cr_assert(utils_list_cmp(l2, ret));

    utils_list_free(ret);
    utils_list_free(l2);
}

Test(swapPairs, a003) {
    int d1[] = {};
    struct ListNode * l1 = utils_list_create(d1, 0);

    int d2[] = {};
    struct ListNode * l2 = utils_list_create(d2, 0);

    struct ListNode *ret = swapPairs(l1);

    cr_assert(utils_list_cmp(l2, ret));

    utils_list_free(ret);
    utils_list_free(l2);
}