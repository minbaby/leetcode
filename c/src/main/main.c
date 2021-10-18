#include "148-sort-list/148.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>

int main(int args, char **arv) {
    // [4]     [19]    [14]    [5]     [-3]    [1]     [8]     [5]     [11]    [15]
    int list01[] = {4,19,14,5,-3,1,8,5,11,15};
    struct ListNode* n = utils_list_create(list01, 10);

    // utils_list_print(n);
    struct ListNode *ret = sortList(n);
    utils_list_print(ret);
}



