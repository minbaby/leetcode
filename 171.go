package leetcode

import (
	"math"
	"strings"
)

func titleToNumber(s string) int {
	m := map[string]int{
		"A": 1,
		"B": 2,
		"C": 3,
		"D": 4,
		"E": 5,
		"F": 6,
		"G": 7,
		"H": 8,
		"I": 9,
		"J": 10,
		"K": 11,
		"L": 12,
		"M": 13,
		"N": 14,
		"O": 15,
		"P": 16,
		"Q": 17,
		"R": 18,
		"S": 19,
		"T": 20,
		"U": 21,
		"V": 22,
		"W": 23,
		"X": 24,
		"Y": 25,
		"Z": 26,
	}

	arr := strings.Split(s, "")
	l := len(arr)
	nums := 0
	for i := 0; i < l; i++ {
		nums += m[arr[l-i-1]] * int(math.Pow(26, float64(i)))
	}

	return nums
}

func titleToNumber2(s string) int {
	l := len(s)
	nums := 0
	for i := 0; i < l; i++ {
		nums += int(s[l-1-i]-'A'+1) * int(math.Pow(26, float64(i)))
	}

	return nums
}
