#include "147.h"

/**
 * @see https://leetcode-cn.com/problems/insertion-sort-list/solution/dui-lian-biao-jin-xing-cha-ru-pai-xu-by-leetcode-s/
 * @param head
 * @return
 */
struct ListNode *insertionSortList(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *guard = (struct ListNode *) malloc(sizeof(struct ListNode));
    guard->next = head;

    // 维护已排序部分的最后一个节点，默认给head，即第一个元素当作有序链表
    struct ListNode *lastPosition = head;

    // 待插入元素，跳过第一个元素
    struct ListNode *curr = head->next;

    // 对比，lastPosition 和 curr
    while (curr != NULL) {
        if (lastPosition->val <= curr->val) {
            // 直接对比，curr是last的元素， 不需要移动的情况
            lastPosition = lastPosition->next;
        } else {
            // 需要移动的情况，需要从头开始对比放在哪个坑里
            struct ListNode *prev = guard; // 防止出现，需要插入的元素插入到第一个元素之前的情况
            while (prev->next->val < curr->val) {
                prev = prev->next;
            }
            lastPosition->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastPosition->next;
    }

    struct ListNode *ret = guard->next;
    free(guard);
    return ret;
}