#ifndef LEET_CODE_UTILS_H
#define LEET_CODE_UTILS_H

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void UPrintList(struct ListNode *list);

void utils_list_print(struct ListNode *list);

struct ListNode *utils_list_create(const int *list, int num);

bool utils_list_cmp(struct ListNode *l1, struct ListNode *l2);

void utils_print_array(char *str);

void utils_list_free(struct ListNode *list);

#endif //LEET_CODE_UTILS_H
