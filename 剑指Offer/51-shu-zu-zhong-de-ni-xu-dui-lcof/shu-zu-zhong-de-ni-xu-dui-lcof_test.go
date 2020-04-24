package _1_shu_zu_zhong_de_ni_xu_dui_lcof

import (
	"leetcode/Tools"
	"testing"
)

func Test_reversePairs(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "[7,5,6,4]",
			args: args{
				Tools.ParseIntArray("[7,5,6,4]"),
			},
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reversePairs(tt.args.nums); got != tt.want {
				t.Errorf("reversePairs() = %v, want %v", got, tt.want)
			}
		})
	}
}
