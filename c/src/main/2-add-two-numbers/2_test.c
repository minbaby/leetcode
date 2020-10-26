#include <criterion/criterion.h>
#include <stdio.h>
#include "2.h"

Test(AddTwoNumbers001, a001) {
    struct ListNode *h1 = &((struct ListNode) {.val = 2});
    h1->next = &((struct ListNode) {.val=4});
    h1->next->next = &((struct ListNode) {.val=3});

    struct ListNode *h2 = &((struct ListNode) {.val = 5});
    h2->next = &((struct ListNode) {.val=6});
    h2->next->next = &((struct ListNode) {.val=4});

    struct ListNode *expected = &((struct ListNode) {.val = 7});
    expected->next = &((struct ListNode) {.val = 0});
    expected->next->next = &((struct ListNode) {.val = 8});


    struct ListNode* ret = addTwoNumbers(h1, h2);
//    while (expected != NULL) {
//        printf("%d(", expected->val);
//
//        ret = ret->next;
//        expected = expected->next;
//        cr_expect(ret->val == expected->val, "result error");
//    }
}
//Test(AddTwoNumbers001, a002) {
//    struct ListNode h1 = {
//            .val = 2
//    };
//    h1.next = &((struct ListNode) {.val=4});
//    h1.next = &((struct ListNode) {.val=3});
//
//    while (h1.next != NULL) {
//        printf("%d(", h1.val);
//        h1 = *h1.next;
//    }
//
//    cr_assert_eq(1, 1);
//}