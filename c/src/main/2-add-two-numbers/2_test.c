#include <criterion/criterion.h>
#include <stdio.h>
#include "../../utils.h"
#include "2.h"

Test(AddTwoNumbers001, a001) {
    int l1[] = {2, 4, 3};
    struct ListNode *h1 = UIntToList(l1, 3);

    int l2[] = {5, 6, 4};
    struct ListNode *h2 = UIntToList(l2, 3);

    int l3[] = {7, 0, 8};
    struct ListNode *expected = UIntToList(l3, 3);

    struct ListNode* ret = addTwoNumbers(h1, h2);

    cr_assert(UListEqual(expected, ret), "not equal");
}

Test(AddTwoNumbers001, a002) {
    int l1[] = {9,9,9,9,9,9,9};
    struct ListNode *h1 = UIntToList(l1, 7);

    int l2[] = {9,9,9,9};
    struct ListNode *h2 = UIntToList(l2, 4);

    int l3[] = {8,9,9,9,0,0,0,1};
    struct ListNode *expected = UIntToList(l3, 8);

    struct ListNode* ret = addTwoNumbers(h1, h2);

    cr_assert(UListEqual(expected, ret), "not equal");
}