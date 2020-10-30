
#ifndef LEET_CODE_3_H
#define LEET_CODE_3_H

//@see https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

// 1. index = (int) char, 可以理解成一个简单的 hash 函数, 把字符转换成 index，继而吧数组转化成 hash 表用
// 2. value = char_origin_index, hash表中 value 为原字符串中字符的索引
// 3. 当出现重复值的时候可以很方便都找到，重复的字符在字符串都位置，然后从该位置下一位重新计算
int lengthOfLongestSubstring(char * s);

#endif //LEET_CODE_3_H
