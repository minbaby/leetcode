package leetcode

import (
	"math"
	"strconv"
)

func reverse(x int) int {

	str := strconv.Itoa(x)
	l := len(str)
	newStr := ""
	i := 0
	f := false
	if str[0] == '-' {
		f = true
		i = 1
	}
	for ; i < l; i++ {
		newStr = string(str[i]) + newStr
	}

	ret, _ := strconv.Atoi(newStr)
	if f {
		ret = -ret
	}

	if ret > math.MaxInt32 || ret < math.MinInt32 {
		return 0
	}
	return ret
}
