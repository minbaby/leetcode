#include <stdio.h>
#include <stdlib.h>
#include "19-remove-nth-node-from-end-of-list/19.h"

int main(int args, char **arv) {
    int list[] = {1,2};
    struct ListNode *h1 = utils_list_create(list, 2);

    int listExpected[] = {1};
    struct ListNode *expected = utils_list_create(listExpected, 1);

    struct ListNode *ret = removeNthFromEnd(h1, 1);

    (utils_list_cmp(expected, ret));

//    utils_list_free(ret);
    utils_list_free(expected);
    utils_list_free(h1);
}