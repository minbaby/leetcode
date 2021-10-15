#include "148.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *pHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    pHead->next = head;
    pHead->val = -1;

    int swap = true;
    while(swap) {
        swap = false;
        struct ListNode *first = pHead;
        while (first != NULL && first->next != NULL && first->next->next != NULL)
        {
            if (first->next->val >= first->next->next->val) {
                struct ListNode *tmp = first->next;

                first->next = first->next->next;
                tmp->next = first->next->next;
                first->next->next = tmp;
                swap = true;
            }

            first = first->next;
        }
    }
    

    struct ListNode *ret = pHead->next;
    free(pHead);
    return ret;
}