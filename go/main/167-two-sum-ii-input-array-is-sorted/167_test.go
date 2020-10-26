package _67_two_sum_ii_input_array_is_sorted

import (
	"leetcode/tools"
	"reflect"
	"testing"
)

//输入: numbers = [2, 7, 11, 15], target = 9
//输出: [1,2]
//解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
func Test_twoSum(t *testing.T) {
	type args struct {
		numbers []int
		target  int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			"numbers = [2, 7, 11, 15], target = 9",
			args{[]int{2, 7, 11, 15}, 9},
			[]int{1, 2},
		},
		{
			"numbers = [2,3,4], target = 6",
			args{[]int{2, 3, 4}, 6},
			[]int{1, 3},
		},
		{
			"numbers = [0,0,3,4], target = 0",
			args{[]int{0, 0, 3, 4}, 0},
			[]int{1, 2},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := twoSum(tt.args.numbers, tt.args.target); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("twoSum() = %v, want %v", got, tt.want)
			}
		})
		if tools.InCI() {
			continue
		}
		t.Run(tt.name+"#my", func(t *testing.T) {
			if got := twoSumMy(tt.args.numbers, tt.args.target); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("twoSum() = %v, want %v", got, tt.want)
			}
		})
	}
}
