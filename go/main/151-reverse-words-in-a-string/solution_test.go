package _51_reverse_words_in_a_string

import (
	"leetcode/tools"
	"testing"
)

func Test_reverseWords(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want string
	}{
		{
			"the sky is blue",
			args{
				"the sky is blue",
			},
			"blue is sky the",
		},
		{
			"  the sky is blue",
			args{
				"  the sky is blue",
			},
			"blue is sky the",
		},
		{
			"  the sky   is blue",
			args{
				"  the sky   is blue",
			},
			"blue is sky the",
		},
		{
			"  the sky   is blue",
			args{
				"  the sky   is blue",
			},
			"blue is sky the",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reverseWords(tt.args.s); got != tt.want {
				t.Errorf("reverseWords() = %v, want %v", got, tt.want)
			}
		})

		if tools.InCI() {
			continue
		}

		t.Run(tt.name, func(t *testing.T) {
			if got := reverseWords2(tt.args.s); got != tt.want {
				t.Errorf("reverseWords2() = %v, want %v", got, tt.want)
			}
		})
	}
}