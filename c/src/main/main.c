#include "151-reverse-words-in-a-string/151.h"
#include <stdio.h>


int main(int args, char **arv) {
    char *input = "a";
    char *expected = "";

    char * x = reverseWords(input);
    printf("ret: [%s]", x);
}
