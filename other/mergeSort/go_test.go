package mergeSort

import (
	"leetcode/tools"
	"reflect"
	"testing"
)

func Test_mergeSort(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			"[1,3,5,7,9,2,4,6,8,0]",
			args{
				tools.ParseIntArray("[1,3,5,7,9,2,4,6,8,0]"),
			},
			tools.ParseIntArray("[0,1,2,3,4,5,6,7,8,9]"),
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := mergeSort(tt.args.nums); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("mergeSort() = %v, want %v", got, tt.want)
			}
		})
	}
}
