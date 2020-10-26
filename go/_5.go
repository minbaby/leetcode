package leetcode

func longestPalindrome(s string) string {
	maxP1 := 0
	maxP2 := 1

	l := len(s)

	if l == 0 || l == 1 {
		return s
	}

	for i := 0; i < l; i++ {
		for j := 0; j <= i; j++ {

			if s[j] != s[i-j] {
				continue
			}
			if i-j > maxP2-maxP1 {
				maxP2 = i
				maxP1 = j
			}
		}
	}

	return string(s[maxP1:maxP2])
}
