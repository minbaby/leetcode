package _02_happy_number

import (
	"strconv"
)

func isHappy(n int) bool {
	m := map[int]byte{}

	t := getNumSum(n)
	for true {
		t = getNumSum(t)
		if t == 1 {
			return true
		}
		if _, ok := m[t]; ok {
			return false
		}
		m[t] = 0
	}

	return false
}

func isHappy2(n int) bool {
	m := map[int]byte{}

	t := getNumSum2(n)
	for true {
		t = getNumSum2(t)
		if t == 1 {
			return true
		}
		if _, ok := m[t]; ok {
			return false
		}
		m[t] = 0
	}

	return false
}

func getNumSum(n int) int {
	str := strconv.Itoa(n)
	ret := 0
	for _, v := range str {
		i, _ := strconv.Atoi(string(v))
		ret += i * i
	}

	return ret
}

func getNumSum2(n int) int {
	l := n
	ret := 0
	t := 0
	for l != 0 {
		t = l % 10
		l /= 10
		ret += t * t
	}

	return ret
}
