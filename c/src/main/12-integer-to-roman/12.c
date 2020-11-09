#include "12.h"
#include <uthash.h>
#include <stdlib.h>
#include <stdio.h>

struct mm
{
    int key;
    char *value;
    UT_hash_handle hh;
};

struct mm * find_node(struct mm * data, int key) {
    struct mm * ret;
    HASH_FIND_INT(data, &key, ret);
    return ret;
}

char *intToRoman(int num)
{
    char *ret = (char *) malloc(sizeof(char*) * 10);
    memset(ret, '\0', sizeof(sizeof(ret)));

    char *cM[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    
    struct mm *data = NULL;

    for (size_t i = 0; i < 13; i++)
    {
        struct mm *d1 = (struct mm *)malloc(sizeof(struct mm));
        d1->key = nums[i];
        d1->value = cM[i];
        HASH_ADD_INT(data, key, d1);
    }

    size_t index = 0;
    struct mm *t;
    for (int j = 12; j >= 0; j--)
    {
        t = find_node(data, nums[j]);

        while (num > 0)
        {
            int tmp = num - nums[j];
            if (tmp >= 0)
            {
                strcat(ret, t->value);
                index++;
                num -= nums[j];
            }
            else
            {
                break;
            }
        }
    }

    // 结束清理内存
    struct mm *el, *tmp;
    HASH_ITER(hh, data, el, tmp)
    {
        HASH_DEL(data, el);
        free(el);
    }
    free(data);

    return ret;
}
