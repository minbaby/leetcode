package _1_first_missing_positive

import (
	"leetcode/tools"
	"testing"
)

func Test_firstMissingPositive(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"[7,8,9,11,12]",
			args{
				tools.ParseIntArray("[7,8,9,11,12]"),
			},
			1,
		},
		{
			"[3,4,-1,1]",
			args{
				tools.ParseIntArray("[3,4,-1,1]"),
			},
			2,
		},
		{
			"[1,2,0]",
			args{
				tools.ParseIntArray("[1,2,0]"),
			},
			3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := firstMissingPositive(tt.args.nums); got != tt.want {
				t.Errorf("firstMissingPositive() = %v, want %v", got, tt.want)
			}
		})
	}
}
