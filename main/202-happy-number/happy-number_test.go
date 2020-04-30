package _02_happy_number

import (
	"leetcode/tools"
	"testing"
)

func Test_isHappy(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			"19-true",
			args{
				19,
			},
			true,
		},
		{
			"121217828998981212-true",
			args{
				121217828998981212,
			},
			false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := isHappy(tt.args.n); got != tt.want {
				t.Errorf("isHappy() = %v, want %v", got, tt.want)
			}
		})
		if tools.InCI() {
			continue
		}
		t.Run(tt.name+"|happy2", func(t *testing.T) {
			if got := isHappy2(tt.args.n); got != tt.want {
				t.Errorf("isHappy2() = %v, want %v", got, tt.want)
			}
		})
	}
}
