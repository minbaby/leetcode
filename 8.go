package leetcode

import (
	"math"
	"strings"
)

func myAtoi(str string) int {
	str = strings.Trim(str, " ")

	ret := 0

	l := len(str)

	if l == 0 {
		return 0
	}

	f := false
	prefix := false

	switch str[0] {
	case '-':
		f = true
		prefix = true
	case '+':
		prefix = true
	case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
		l = l
	default:
		return 0
	}

	list := []int{}

	i := 0
	if prefix {
		i = 1
	}
	start := false
	for ; i < len(str); i++ {
		t := char2int(str[i])

		if !start && t == 0 {
			continue
		} else {
			start = true
		}

		if t == -1 {
			break
		}

		list = append(list, t)
	}

	ll := len(list)

	if ll > 10 && f {
		return math.MinInt32
	}

	if ll > 10 && !f {
		return math.MaxInt32
	}

	for j := 0; j < ll; j++ {
		ret += list[j] * square(ll-j-1)
	}

	if f {
		ret = -ret
	}

	if ret > math.MaxInt32 {
		return math.MaxInt32
	}

	if ret < math.MinInt32 {
		return math.MinInt32
	}

	return ret
}

func char2int(u uint8) int {
	switch u {
	case '1':
		return 1
	case '2':
		return 2
	case '3':
		return 3
	case '4':
		return 4
	case '5':
		return 5
	case '6':
		return 6
	case '7':
		return 7
	case '8':
		return 8
	case '9':
		return 9
	case '0':
		return 0
	}

	return -1
}

func square(u int) int {
	ret := 1
	for i := 0; i < u; i++ {
		ret = ret * 10
	}

	return ret
}
