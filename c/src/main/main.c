#include "23-merge-k-sorted-lists/23.h"
#include "../utils.h"
#include <stdlib.h>

int main(int args, char **arv) {
    int d1[] = {1, 4, 5};
    struct ListNode *l1 = utils_list_create(d1, 3);

    int d2[] = {1, 3, 4};
    struct ListNode *l2 = utils_list_create(d2, 3);

    int d3[] = {2, 6};
    struct ListNode *l3 = utils_list_create(d3, 2);

    struct ListNode * l[] = {l1, l2, l3};

    struct ListNode * ret = mergeKLists2(l, 3);

    utils_list_print(ret);

    while (ret) {
        struct ListNode * tmp = ret;
        ret = ret->next;
        free(tmp);
    }
}

