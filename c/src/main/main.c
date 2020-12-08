#include "../utils.h"
#include "25-reverse-nodes-in-k-group/25.h"
#include <stdlib.h>

int main(int args, char **arv) {
    int d1[] = {1, 2, 3, 4, 5};
    struct ListNode *l1 = utils_list_create(d1, 5);

    struct ListNode *ret = reverseKGroup(l1, 2);

    utils_list_print(ret);
    utils_list_free(ret);
}

