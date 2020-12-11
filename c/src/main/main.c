#include "28-implement-strstr/28.h"
#include <stdlib.h>
#include <stdio.h>

int main(int args, char **arv) {
    char *ha[] = {
            "hello",
            "aaaaa",
            "ababab",
            "aaa",
            "mississippi",
            "mississippi",
            "aaaa",
    };

    char *ne[] = {
            "ll",
            "bba",
            "",
            "aaaa",
            "issip",
            "issipi",
            "baaa",
    };

    int n =
//            1
            7
    ;

    for (int i = 0; i < n; ++i) {
        int x = strStr2(ha[i], ne[i]);
        printf("[%d]@@ %d @@ \n", i, x);
    }

    printf("end");
}

