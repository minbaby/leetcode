#include "13.h"

int romanToInt(char *s)
{
    int ret = 0;

    while (*s)
    {
        if (*s == 'M')
        {
            ret += 1000;
        }
        else if (*s == 'D')
        {
            ret+=500;
        }
        else if (*s == 'C' && (*(s + 1) == 'M' || *(s + 1) == 'D'))
        {
            ret -= 100;
            s++;
            continue;
        }
        else if (*s == 'C')
        {
            ret += 100;
        }
        else if (*s == 'L')
        {
            ret += 50;
        }
        else if (*s == 'X' && (*(s + 1) == 'L' || *(s + 1) == 'C'))
        {
            ret -= 10;
            s++;
            continue;
        }
        else if (*s == 'X')
        {
            ret += 10;
        }
        else if (*s == 'V')
        {
            ret += 5;
        }
        else if (*s == 'I' && (*(s + 1) == 'V' || *(s + 1) == 'X'))
        {
            ret -= 1;
            s++;
            continue;
        }
        else if (*s == 'I')
        {
            ret += 1;
        }
        s++;
    }

    return ret;
}