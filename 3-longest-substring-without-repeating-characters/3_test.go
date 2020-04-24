package __longest_substring_without_repeating_characters

import "testing"

type _data struct {
	Str string
	Len int
}

func TestLengthOfLongestSubstring(t *testing.T) {
	data := []_data{
		_data{
			Str: "bbbbb",
			Len: 1,
		},
		_data{
			Str: "abcabcbb",
			Len: 3,
		},
		_data{
			Str: "pwwkew",
			Len: 3,
		},
		_data{
			Str: "dvdf",
			Len: 3,
		},
	}

	for i := range data {
		if l := lengthOfLongestSubstring(data[i].Str); data[i].Len != l {
			t.Errorf("(%s) (%d): %d != %d", data[i].Str, data[i].Len, l, data[i].Len)
		}
	}
}
