#include <malloc.h>
#include "21.h"


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }

    if (l2 == NULL) {
        return l1;
    }

    struct ListNode *ret = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = ret;
    while (true) {
        if (l1 == NULL || l2 == NULL) {
            break;
        }

        if (l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        } else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }

    while (l1) {
        p->next = l1;
        l1 = l1->next;
        p = p->next;
    }

    while (l2) {
        p->next = l2;
        l2 = l2->next;
        p = p->next;
    }


    struct ListNode *r = ret->next;
    free(ret);

    return r;
}