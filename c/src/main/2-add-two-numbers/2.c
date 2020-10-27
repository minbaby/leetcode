#include <stdio.h>
#include <stdlib.h>
#include "2.h"
#include "../../utils.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));

    int plus = 0;
    struct ListNode *pp = head;
    while (l1 != NULL && l2 != NULL) {
        int _val = l1->val + l2->val + plus;
        plus = 0;

        if (_val >= 10) {
            _val -= 10;
            plus++;
        }

        struct ListNode *_new = (struct ListNode *) malloc(sizeof(struct ListNode));
        _new->val = _val;

        pp->next = _new;
        pp = _new;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL) {
        struct ListNode *_new = (struct ListNode *) malloc(sizeof(struct ListNode));
        _new->val = l1->val;

        pp->next = _new;
        pp = _new;

        l1 = l1->next;
    }

    while (l2 != NULL) {
        struct ListNode *_new = (struct ListNode *) malloc(sizeof(struct ListNode));
        _new->val = l2->val;

        pp->next = _new;
        pp = _new;

        l2 = l2->next;
    }

    return head->next;
}