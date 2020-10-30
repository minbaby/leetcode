#include <stdio.h>
#include <stdlib.h>
#include "2.h"
#include "../../utils.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    INIT_NODE(head, 0);

    int plus = 0;
    struct ListNode *pp = head;
    int _val;
    while (l1 != NULL && l2 != NULL) {
        _val = l1->val + l2->val + plus;
        HANDLE_VAL(_val);

        INIT_NODE(_new, _val);

        pp->next = _new;
        pp = _new;

        l1 = l1->next;
        l2 = l2->next;
    }

    HANDLE_X(l1);
    HANDLE_X(l2);

    if (plus) {
        INIT_NODE(_new, 1);

        pp->next = _new;
    }

    return head->next;
}