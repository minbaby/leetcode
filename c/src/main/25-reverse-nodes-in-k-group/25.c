#include "25.h"
#include "../../utils.h"
#include <stdlib.h>

// 每次步进N，得到头尾指针
// 头尾指针，反转的时候判断头指针是否和尾指针重合，重合即结束

static struct ListNode **reverse(struct ListNode *head, struct ListNode *tail) {
    struct ListNode **ret = (struct ListNode **) malloc(sizeof(struct ListNode) * 2);

    struct ListNode *prev = tail->next;
    struct ListNode *p = head;
    while (prev != tail) {
        struct ListNode *tmp = p->next;
        p->next = prev;
        prev = p;
        p = tmp;
    }

    ret[0] = tail;
    ret[1] = head;

    return ret;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    struct ListNode *hair = (struct ListNode *) malloc(sizeof(struct ListNode));
    hair->next = head;

    struct ListNode *pre = hair;

    while (head != NULL) {
        struct ListNode *tail = pre;

        for (int i = 0; i < k; ++i) {
            tail = tail->next;

            if (tail == NULL) {
                struct ListNode *tmp = hair->next;
                free(hair);
                return tmp;
            }
        }

        struct ListNode *next = tail->next;
        struct ListNode **val = reverse(head, tail);

        head = val[0];
        tail = val[1];

        free(val);

        pre->next = head;
        tail->next = next;
        pre = tail;
        head = tail->next;

    }

    struct ListNode *tmp = hair->next;
    free(hair);
    return tmp;
}
