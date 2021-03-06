#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const int MAX_LOOP = 100;

void UPrintList(struct ListNode *list) {
    printf("\n========s========\n");
    struct ListNode *listNode = list;

    int num = 0;
    while (listNode != NULL) {
        if (num >= MAX_LOOP) {
            printf("%s \n", "Max Loop");
            break;
        }
        printf("[%d]\t", listNode->val);
        listNode = listNode->next;
        num++;
    }

    printf("\n========e========\n");
}

void utils_list_print(struct ListNode *listNode) {
    UPrintList(listNode);
}

struct ListNode *utils_list_create(const int *list, int num) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    struct ListNode *p = head;
    for (int i = 0; i < num; i++) {
        struct ListNode *n = (struct ListNode *) malloc(sizeof(struct ListNode));
        n->val = list[i];
        n->next = NULL;

        p->next = n;
        p = n;
    }

    struct ListNode *ret = head->next;
    free(head);
    return ret;
}

bool utils_list_cmp(struct ListNode *l1, struct ListNode *l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if ((l1 == NULL && l2 != NULL || l1 != NULL && l2 == NULL)) {
        return false;
    }

    return true;
}

void utils_list_free(struct ListNode *list) {
    struct ListNode *tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void utils_print_array(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        printf("[%c]\t", str[i]);
    }
}