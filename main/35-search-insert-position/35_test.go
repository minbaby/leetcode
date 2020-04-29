package _5_search_insert_position

import (
	"leetcode/tools"
	"testing"
)

func Test_searchInsert(t *testing.T) {
	type args struct {
		nums   []int
		target int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"[1,3,5,6], 5",
			args{[]int{1, 3, 5, 6}, 5},
			2,
		},
		{
			" [1,3,5,6], 2",
			args{[]int{1, 3, 5, 6}, 2},
			1,
		},
		{
			" [1,3,5,6], 7",
			args{[]int{1, 3, 5, 6}, 7},
			4,
		},
		{
			" [1,3,5,6], 0",
			args{[]int{1, 3, 5, 6}, 0},
			0,
		},
		{
			" [1,1,1,1], 0",
			args{[]int{1, 1, 1, 1}, 0},
			0,
		},
		{
			" [1,3], 1",
			args{[]int{1, 3}, 1},
			0,
		},
		{
			" [1], 0",
			args{[]int{1}, 0},
			0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := searchInsert(tt.args.nums, tt.args.target); got != tt.want {
				t.Errorf("searchInsert() = %v, want %v", got, tt.want)
			}
		})

		if tools.InCI() {
			continue
		}

		t.Run(tt.name, func(t *testing.T) {
			if got := searchInsert2(tt.args.nums, tt.args.target); got != tt.want {
				t.Errorf("searchInsert() = %v, want %v", got, tt.want)
			}
		})
	}
}
