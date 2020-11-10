#include "14.h"
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        char *ret = (char *)malloc(sizeof(char *));
        ret[0] = '\0';
        return ret;
    }

    char *first = strs[0];
    size_t len = strlen(first);
    char *ret = (char *)malloc(sizeof(char *) * (len + 1));
    memset(ret, '\0', sizeof(char *) * (len + 1));

    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 1; j < strsSize; j++)
        {
            if (first[i] != strs[j][i])
            {
                strncpy(ret, first, i);
                return ret;
            }
        }
    }

    strcpy(ret, first);
    return ret;
}