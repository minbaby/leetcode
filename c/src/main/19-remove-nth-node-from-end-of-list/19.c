#include "19.h"
#include <stdlib.h>

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;

    while (p1 != NULL) {
        if (n < 0) {
            p2 = p2->next;
        }
        n--;
        p1 = p1->next;
    }

    if (n == 0) {
        return head->next;
    }

    struct ListNode *tmp = p2->next;
    p2->next = p2->next->next;
    free(tmp);

    return head;
}