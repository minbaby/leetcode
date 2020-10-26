package _095_find_in_mountain_array

import (
	"leetcode/tools"
	"testing"
)

func Test_findInMountainArray(t *testing.T) {
	type args struct {
		target      int
		mountainArr *MountainArray
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"[1,2,3,4,5,3,1] 3",
			args{
				target:      3,
				mountainArr: New(tools.ParseIntArray(`[1,2,3,4,5,3,1]`)),
			},
			2,
		},
		{
			"[1,2,4,5,3,1] 3",
			args{
				target:      3,
				mountainArr: New(tools.ParseIntArray(`[1,2,4,5,3,1]`)),
			},
			4,
		},
		{
			"[0,1,2,4,2,1] 3",
			args{
				target:      3,
				mountainArr: New(tools.ParseIntArray(`[0,1,2,4,2,1]`)),
			},
			-1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := findInMountainArray(tt.args.target, tt.args.mountainArr); got != tt.want {
				t.Errorf("findInMountainArray() = %v, want %v", got, tt.want)
			}
			if tt.args.mountainArr.Count >= 100 {
				t.Errorf("MountainArray.get call times=%v", tt.args.mountainArr.Count)
			}
		})
	}
}
