#include "148-sort-list/148.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>

int main(int args, char **arv) {
    int list01[] = {-1,5,3,4,0};
    struct ListNode *n = utils_list_create(list01, 5);
    utils_list_print(n);
    struct ListNode *ret = sortList(n);
    utils_list_print(ret);
}



