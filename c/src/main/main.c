#include <stdio.h>
#include <stdbool.h>
#include "21-merge-two-sorted-lists/21.h"
#include "../utils.h"

int main(int args, char **arv) {
    int d[] = {-9, 3};
    struct ListNode *l1 = utils_list_create(d, 2);

    int d1[] = {5, 7};
    struct ListNode *l2 = utils_list_create(d1, 2);

    struct ListNode *l3 = mergeTwoLists(l1, l2);


    UPrintList(l3);
}