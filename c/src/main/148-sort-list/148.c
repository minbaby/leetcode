#include "148.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 归并排序
 * 
 */

// 执行到这个地方的时候，head，和 tail 一定是有序的，所以这个地方的逻辑拆解成了，合并两个有序列表
struct ListNode *merge(struct ListNode *head, struct ListNode *head2)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    dummyHead->val = -1;
    struct ListNode *tmp = dummyHead;
    struct ListNode *tmp1 = head;
    struct ListNode *tmp2 = head2;

    while (tmp1 != NULL && tmp2 != NULL) // 这个地方需要思考一下
    {
        if (tmp1->val > tmp2->val)
        {
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }
        else
        {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }

    // 如果两个链表长度不一样，则最后必然有一个没有处理完
    if (tmp1 != NULL)
    {
        tmp->next = tmp1;
    }
    else if (tmp2 != NULL)
    {
        tmp->next = tmp2;
    }

    struct ListNode *ret = dummyHead->next;
    free(dummyHead);
    return ret;
}

// merge 的前提，是分割成两个链表
struct ListNode *toSortList(struct ListNode *head, struct ListNode *tail)
{
    if (head == NULL)
    {
        return head;
    }

    // 当原始链表中只有一个节点的时候，tail为NULL，则依旧适用
    if (head->next == tail)
    {
        head->next = NULL;
        return head;
    }

    // 使用快慢指针，找到 head 这个链表的中间指针
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != tail)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail)
        {
            fast = fast->next;
        }
    }
    struct ListNode *mid = slow;

    // 递归成两个有序链表，然后 merge进行有序链表合并
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

struct ListNode *sortList(struct ListNode *head)
{
    return toSortList(head, NULL);
}