#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../../utils.h"

#ifndef LEET_CODE_148_H
#define LEET_CODE_148_H

//@see https://leetcode-cn.com/problems/sort-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 方法一：自顶向下归并排序
// 时间复杂度 O(n log n)  n 是链表长度
// 空间复杂度 O(log n)    n 是链表长度，空间复杂度主要取决于递归调用的栈空间。
struct ListNode* sortList(struct ListNode* head);

#endif // LEET_CODE_148_H