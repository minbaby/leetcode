#include <stdio.h>
#include "5-longest-palindromic-substring/5.h"
#include "../utils.h"

int main(int args, char **arv) {
    char* _n = longestPalindrome("babad");
    utils_print_array(_n);
}