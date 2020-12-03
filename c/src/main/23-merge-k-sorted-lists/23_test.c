#include "23.h"
#include "../../utils.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(mergeKLists, a001) {
    int d1[] = {1, 4, 5};
    struct ListNode *l1 = utils_list_create(d1, 3);

    int d2[] = {1, 3, 4};
    struct ListNode *l2 = utils_list_create(d2, 3);

    int d3[] = {2, 6};
    struct ListNode *l3 = utils_list_create(d3, 2);

    struct ListNode *l[] = {l1, l2, l3};

    int de[] = {1, 1, 2, 3, 4, 4, 5, 6};
    struct ListNode *expected = utils_list_create(de, 8);

    struct ListNode *ret = mergeKLists(l, 3);
    utils_list_cmp(expected, ret);

    utils_list_free(ret);
    utils_list_free(expected);
}

Test(mergeKLists, a002) {
    int d1[] = {1, 4, 5};
    struct ListNode *l1 = utils_list_create(d1, 3);

    int d2[] = {1, 3, 4};
    struct ListNode *l2 = utils_list_create(d2, 3);

    int d3[] = {2, 6};
    struct ListNode *l3 = utils_list_create(d3, 2);

    struct ListNode *l[] = {l1, l2, l3};

    int de[] = {1, 1, 2, 3, 4, 4, 5, 6};
    struct ListNode *expected = utils_list_create(de, 8);

    struct ListNode *ret2 = mergeKLists2(l, 3);
    utils_list_cmp(expected, ret2);

    utils_list_free(ret2);
    utils_list_free(expected);
}