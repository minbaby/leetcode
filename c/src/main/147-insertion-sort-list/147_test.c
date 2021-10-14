#include "147.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(insertionSortList, a001) {
    int d1[] = {4, 2, 1, 3};
    struct ListNode *l1 = utils_list_create(d1, 4);

    int expectedArr[] = {1, 2, 3, 4};
    struct ListNode *expectedList = utils_list_create(expectedArr, 4);

    struct ListNode *actual = insertionSortList(l1);

    cr_assert_(utils_list_cmp(expectedList, actual));

    utils_list_free(expectedList);
    utils_list_free(actual);
}

Test(insertionSortList, a002) {
    int d1[] = {-1, 5, 3, 4, 0};
    struct ListNode *l1 = utils_list_create(d1, 5);

    int expectedArr[] = {-1, 0, 3, 4, 5};
    struct ListNode *expectedList = utils_list_create(expectedArr, 5);

    struct ListNode *actual = insertionSortList(l1);

    cr_assert_(utils_list_cmp(expectedList, actual));

    utils_list_free(expectedList);
    utils_list_free(actual);
}
