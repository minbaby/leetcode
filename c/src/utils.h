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

#define ARRAY_CREATE(A, row, col, data)            \
    A = (int **)malloc(sizeof(int) * (row) * (col));   \
    for (int i = 0; i < (row); i++)                  \
    {                                              \
        int *t = (int *)malloc(sizeof(int) * (col)); \
        for (int j = 0; j < (col); j++)              \
        {                                          \
            *(t + j) = (data)[i][j];                 \
        }                                          \
        *((A) + i) = t;                              \
    }

#define ARRAY_FREE(A, row) \
    for(int i=0; i< (row); i++) \
    {                           \
        free((A)[i]);           \
    }                           \
    free(A);

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

#endif //LEET_CODE_UTILS_H