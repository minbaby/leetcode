#include <stdlib.h>

#ifndef LEET_CODE_2_H
#define LEET_CODE_2_H

//see https://leetcode-cn.com/problems/add-two-numbers/

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);


#endif //LEET_CODE_2_H

#define INIT_NODE(name, _val) \
    struct ListNode *name = malloc(sizeof(struct ListNode)); \
    name->val = _val; \
    name->next = NULL;

#define HANDLE_VAL(val) \
            plus = 0; \
            if (_val >= 10) { \
                _val -= 10; \
                plus++; \
            }

#define HANDLE_X(list) \
     while (list != NULL) { \
        _val = list->val + plus;\
        HANDLE_VAL(_val); \
        INIT_NODE(_new, _val); \
        pp->next = _new; \
        pp = _new; \
        list = list->next; \
    }