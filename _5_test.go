package leetcode

import "testing"

type _node5 struct {
	Data string
	Act  string
}

func TestLongestPalindrome(t *testing.T) {
	data := []_node5{
		{
			Data: "babad",
			Act:  "aba",
		},
		{
			Data: "cbbd",
			Act:  "bb",
		},
		{
			Data: "a",
			Act:  "a",
		},
		{
			"ab",
			"a",
		},
		{
			"bb",
			"bb",
		},
	}

	for index := range data {
		if tmp := longestPalindrome(data[index].Data); tmp != data[index].Act {
			t.Errorf("%s != %s", tmp, data[index].Act)
		}
	}
}
