package leetcode

import "testing"

type _node4 struct {
	F      []int
	S      []int
	Expect float64
}

func TestFindMedianSortedArrays(t *testing.T) {
	data := []_node4{
		_node4{
			F:      []int{1, 3},
			S:      []int{2},
			Expect: 2,
		},
		_node4{
			F:      []int{1, 2},
			S:      []int{3, 4},
			Expect: 2.5,
		},
		_node4{
			F:      []int{3},
			S:      []int{-2, -1},
			Expect: -1,
		},
	}
	for index := range data {
		if a := findMedianSortedArrays(data[index].F, data[index].S); data[index].Expect != a {
			t.Errorf("not equal %f != %f", a, data[index].Expect)
		}
	}
}
