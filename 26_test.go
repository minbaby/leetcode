package leetcode

import "testing"

func Test_removeDuplicates(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"[1,1,2]",
			args{[]int{1, 1, 2}},
			2,
		},
		{
			"[0,0,1,1,1,2,2,3,3,4]",
			args{[]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}},
			5,
		},
		{
			"[1,2]",
			args{[]int{1, 2}},
			2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := removeDuplicates(tt.args.nums); got != tt.want {
				t.Errorf("removeDuplicates() = %v, want %v", got, tt.want)
			}
		})
	}
}
