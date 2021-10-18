#include "148.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(t_148_sortList, a001) {
    int list01[] = {4,2,1,3};
    struct ListNode* n = utils_list_create(list01, 4);

    struct ListNode* actualList = sortList(n);
   
    int actual[] = {1,2,3,4};
    struct ListNode* expectedList = utils_list_create(actual, 4);

    cr_assert(utils_list_cmp(expectedList, actualList));
}

Test(t_148_sortList, a002) {
    int list01[] = {-1,5,3,4,0};
    struct ListNode* n = utils_list_create(list01, 5);

    struct ListNode* actualList = sortList(n);
   
    int actual[] = {-1,0,3,4,5};
    struct ListNode* expectedList = utils_list_create(actual, 5);

    cr_assert(utils_list_cmp(expectedList, actualList));
}

Test(t_148_sortList, a003) {
    int list01[] = {4,19,14,5,-3,1,8,5,11,15};
    struct ListNode* n = utils_list_create(list01, 10);

    struct ListNode* actualList = sortList(n);
   
    int actual[] = {-3, 1,4,5,5,8,11,14,15,19};
    struct ListNode* expectedList = utils_list_create(actual, 10);

    cr_assert(utils_list_cmp(expectedList, actualList));
}