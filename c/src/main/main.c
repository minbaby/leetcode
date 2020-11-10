#include <stdio.h>
#include <stdlib.h>
#include "14-longest-common-prefix/14.h"

int main(int args, char **arv) {

    char* strs[3] = {
        "flower",
        "flow",
        "flight"
    };

    char* x = longestCommonPrefix(strs, 3);

    printf("%s \n", x);
}