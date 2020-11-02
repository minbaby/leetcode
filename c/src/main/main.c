#include "../utils.h"
#include "2-add-two-numbers/2.h"

int main(int args, char **arv) {
    int l1[] = {2, 4, 3};
    struct ListNode *h1 = UIntToList(l1, 3);

    int l2[] = {5, 6, 4};
    struct ListNode *h2 = UIntToList(l2, 3);

    addTwoNumbers(h1, h2);

//    struct ListNode x1 = {.val=2};
//    struct ListNode x2 = {.val=4};
//    struct ListNode x3 = {.val=3};
//    x1.next = &x2;
//    x2.next = &x3;
//
//    struct ListNode y1 = {.val=5};
//    struct ListNode y2 = {.val=6};
//    struct ListNode y3 = {.val=4};
//    y1.next = &y2;
//    y2.next = &y3;
//
//
//    addTwoNumbers(&x1, &x2);

//    while (&x1 != NULL) {
//        struct ListNode x = x1;
//        free(&x1);
//    }
}