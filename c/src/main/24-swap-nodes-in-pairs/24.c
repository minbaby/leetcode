#include "24.h"
#include <stdlib.h>
#include "../../utils.h"

struct ListNode *swapPairs(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *f = (struct ListNode *) malloc(sizeof(struct ListNode));
    f->next = head;
    f->val = -1;

    struct ListNode *ff = f;
    struct ListNode *p1, *p2;
    while (true) {
        if (ff->next == NULL || ff->next->next == NULL) {
            break;
        }

        p1 = ff->next;
        p2 = ff->next->next;

        ff->next = p2;
        p1->next = p2->next;
        p2->next = p1;

        ff = ff->next->next;
    }

    struct ListNode *ret = f->next;
    free(f);
    return ret;
}
