#include "23.h"
#include <stdlib.h>
#include "../../utils.h"

static struct ListNode *mergeTwo(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->next = NULL;
    head->val = -1;

    struct ListNode *p = head,
            *p1 = l1,
            *p2 = l2;

    struct ListNode *tmp;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val > p2->val) {
            tmp = p2;
            p2 = p2->next;
            p->next = tmp;
        } else {
            tmp = p1;
            p1 = p1->next;
            p->next = tmp;
        }

        p = p->next;
    }

    if (p1) {
        p->next = p1;
    }

    if (p2) {
        p->next = p2;
    }

    struct ListNode *ret = head->next;
    free(head);
    return ret;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    struct ListNode *tmp = NULL;
    for (int i = 0; i < listsSize; ++i) {
        tmp = mergeTwo(tmp, lists[i]);
    }

    return tmp;
}

static struct ListNode *merge(struct ListNode **lists, int l, int r) {
    if (l == r) {
        return lists[l];
    }
    if (l > r) {
        return NULL;
    }

    int mid = (l + r) / 2;
    return mergeTwo(merge(lists, l, mid), merge(lists, mid + 1, r));
}

struct ListNode *mergeKLists2(struct ListNode **lists, int listsSize) {
    return merge(lists, 0, listsSize -1);
}