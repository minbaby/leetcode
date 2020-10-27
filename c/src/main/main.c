#include <stdio.h>
#include "./2-add-two-numbers/2.h"
#include "../utils.h"

int main(int args, char** arv) {
    int l1[] = {2, 4, 3};
    struct ListNode *h1 = UIntToList(l1, 3);

    int l2[] = {5, 6, 4};
    struct ListNode *h2 = UIntToList(l2, 3);

    int l3[] = {7, 0, 8};
    struct ListNode *expected = UIntToList(l3, 3);

    UPrintList(h1);
    UPrintList(h2);
    UPrintList(expected);

    UPrintList(addTwoNumbers(h1, h2));
}