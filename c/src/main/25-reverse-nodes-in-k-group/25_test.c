#include "25.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(reverseKGroup, a001) {
    int d1[] = {1, 2, 3, 4, 5};
    struct ListNode *l1 = utils_list_create(d1, 5);

    int d2[] = {2, 1, 4, 3, 5};
    struct ListNode *l2 = utils_list_create(d2, 5);

    struct ListNode *ret = reverseKGroup(l1, 2);

    cr_assert_(utils_list_cmp(ret, l2));

    utils_list_free(l2);
    utils_list_free(ret);
}