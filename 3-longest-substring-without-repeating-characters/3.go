package __longest_substring_without_repeating_characters

func lengthOfLongestSubstring(s string) int {
	l := len(s)
	p1 := 0
	p2 := 0
	max := 0

	for i := 0; i < l; i++ {
		for j := p1; j < p2; j++ {
			if s[j] == s[p2] {
				p1 = j + 1
				break
			}
		}

		if (p2 - p1 + 1) > max {
			max = p2 - p1 + 1
		}

		p2++
	}
	return max
}
