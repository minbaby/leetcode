#include "21.h"
#include <criterion/criterion.h>

Test(mergeTwoLists, a001) {
    int d[] = {1, 2, 4};
    struct ListNode *l1 = utils_list_create(d, 3);

    int d1[] = {1, 3, 4};
    struct ListNode *l2 = utils_list_create(d1, 3);

    struct ListNode *l3 = mergeTwoLists(l1, l2);

    int ret[] = {1, 1, 2, 3, 4, 4};
    struct ListNode *lRet = utils_list_create(ret, 6);

    cr_assert(utils_list_cmp(l3, lRet));

    utils_list_free(l3);
    utils_list_free(lRet);
}

Test(mergeTwoLists, a002) {
    struct ListNode *l1 = NULL;

    struct ListNode *l2 = NULL;

    struct ListNode *l3 = mergeTwoLists(l1, l2);

    struct ListNode *lRet = NULL;

    cr_assert(utils_list_cmp(l3, lRet));

    utils_list_free(l3);
    utils_list_free(lRet);
}

Test(mergeTwoLists, a003) {
    int d[] = {-9, 3};
    struct ListNode *l1 = utils_list_create(d, 2);

    int d1[] = {5, 7};
    struct ListNode *l2 = utils_list_create(d1, 2);

    struct ListNode *l3 = mergeTwoLists(l1, l2);

    int ret[] = {-9, 3, 5, 7};
    struct ListNode *lRet = utils_list_create(ret, 4);

    cr_assert(utils_list_cmp(l3, lRet));

    utils_list_free(l3);
    utils_list_free(lRet);
}