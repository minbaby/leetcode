#include <stdio.h>
#include "2.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *ret = &((struct ListNode) {.val = 0});

    struct ListNode head = {.val=0};

    int plus = 0;
    struct ListNode *p = &head;
    while (l1 != NULL && l2 != NULL) {
        int val = l1->val + l2->val + plus;
        if (plus) {
            plus--;
        }
        if (val > 9) {
            val -= 10;
            plus++;
        }
        struct ListNode _new = {.val = val};
        p->next = &_new;
        p = &_new;

        l1 = l1->next;
        l2 = l2->next;
    }

//    while (l1 != NULL) {
//        struct ListNode _new = {.val = l1->val};
//        p->next = &_new;
//        p = &_new;
//
//        l1 = l1->next;
//    }
//
//    while (l2 != NULL) {
//        struct ListNode _new = {.val = l2->val};
//        p->next = &_new;
//        p = &_new;
//
//        l2 = l2->next;
//    }

    struct ListNode *x = &head;
    while (x != NULL) {
        printf("%d -", x->val);
        x = x->next;
    }

    return head.next;
}