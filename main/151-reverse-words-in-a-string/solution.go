package _51_reverse_words_in_a_string

import "strings"

// 直接内置函数+替换顺序
func reverseWords(s string) string {
	ret := strings.Fields(s)

	for i := 0; i < len(ret)/2; i++ {
		ret[i], ret[len(ret)-i-1] = ret[len(ret)-i-1], ret[i]
	}

	return strings.Join(ret, " ")
}

//trim, split, 清理空格 , 替换顺序
func reverseWords2(s string) string {
	s = strings.TrimSpace(s)
	lst := strings.Split(s, " ")
	var ret []string
	for _, v := range lst {
		if v == "" {
			continue
		}
		ret = append(ret, v)
	}

	for i := 0; i < len(ret)/2; i++ {
		ret[i], ret[len(ret)-i-1] = ret[len(ret)-i-1], ret[i]
	}

	return strings.Join(ret, " ")
}