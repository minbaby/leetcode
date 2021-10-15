#include "148.h"
#include "../../utils.h"
#include <criterion/criterion.h>

Test(t_148_sortList, a001) {
    int list01[] = {4,2,1,3};
    struct ListNode* n = utils_list_create(list01, 4);

    struct ListNode* expectedList = sortList(n);
   
    int actual[] = {1,2,3,4};
    struct ListNode* actualList = utils_list_create(actual, 4);

    cr_assert(utils_list_cmp(expectedList, actualList));
}

Test(t_148_sortList, a002) {
    int list01[] = {-1,5,3,4,0};
    struct ListNode* n = utils_list_create(list01, 5);

    struct ListNode* expectedList = sortList(n);
   
    int actual[] = {-1,0,3,4,5};
    struct ListNode* actualList = utils_list_create(actual, 5);

    cr_assert(utils_list_cmp(expectedList, actualList));
}