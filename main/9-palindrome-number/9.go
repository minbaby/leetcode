package __palindrome_number

import (
	"strconv"
)

func isPalindrome(x int) bool {
	str := strconv.Itoa(x)
	ret := true

	l := len(str)
	for i := 0; i < l/2; i++ {
		if str[i] != str[l-i-1] {
			ret = false
			break
		}
	}

	return ret
}
