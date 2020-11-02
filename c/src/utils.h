#ifndef LEET_CODE_UTILS_H
#define LEET_CODE_UTILS_H

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void UPrintList(struct ListNode *list);

struct ListNode *UIntToList(const int list[], int num);

bool UListEqual(struct ListNode *l1, struct ListNode *l2);

void utils_print_array(char *str);
#endif //LEET_CODE_UTILS_H
