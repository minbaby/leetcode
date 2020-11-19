#include "19.h"
#include <criterion/criterion.h>

Test(removeNthFromEnd, a001) {
    int list[] = {1, 2, 3, 4, 5};
    struct ListNode *h1 = utils_list_create(list, 5);

    int listExpected[] = {1, 2, 3, 5};
    struct ListNode *expected = utils_list_create(listExpected, 4);

    struct ListNode *ret = removeNthFromEnd(h1, 2);

    cr_assert(utils_list_cmp(expected, ret));

    utils_list_free(ret);
    utils_list_free(expected);
}

Test(removeNthFromEnd, a002) {
    int list[] = {1};
    struct ListNode *h1 = utils_list_create(list, 1);

    struct ListNode *expected = NULL;

    struct ListNode *ret = removeNthFromEnd(h1, 1);

    cr_assert(utils_list_cmp(expected, ret));

    utils_list_free(ret);
    utils_list_free(expected);
    utils_list_free(h1);
}

Test(removeNthFromEnd, a003) {
    int list[] = {1,2};
    struct ListNode *h1 = utils_list_create(list, 2);

    int listExpected[] = {1};
    struct ListNode *expected = utils_list_create(listExpected, 1);

    struct ListNode *ret = removeNthFromEnd(h1, 1);

    cr_assert(utils_list_cmp(expected, ret));

    utils_list_free(ret);
    utils_list_free(expected);
}

Test(removeNthFromEnd, a004) {
    int list[] = {1,2};
    struct ListNode *h1 = utils_list_create(list, 2);

    int listExpected[] = {2};
    struct ListNode *expected = utils_list_create(listExpected, 1);

    struct ListNode *ret = removeNthFromEnd(h1, 2);

    cr_assert(utils_list_cmp(expected, ret));

    utils_list_free(h1);
    utils_list_free(expected);
}