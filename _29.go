package leetcode

import "math"

func divide(dividend int, divisor int) int {
	return 0
}

func divide2(dividend int, divisor int) int {
	negative := false

	if dividend < 0 {
		negative = !negative
		dividend = - dividend
	}

	if divisor < 0 {
		negative = !negative
		divisor = - divisor
	}

	c := 0
	tmp := dividend
	for tmp >= divisor {
		tmp = tmp - divisor
		c++
	}

	if negative {
		c = - c
	}

	if c > math.MaxInt32 || c < math.MinInt32 {
		return math.MaxInt32
	}

	return c
}
