package leetcode

import "testing"

type _node struct {
	L1     []int
	L2     []int
	Expect []int
}

func arrToList(l []int) *ListNode {
	if len(l) == 0 {
		return nil
	}

	head := &ListNode{
		Val:  l[0],
		Next: nil,
	}

	tmp := head
	for i := 1; i < len(l); i++ {
		node := &ListNode{
			Val:  l[i],
			Next: nil,
		}

		tmp.Next = node
		tmp = node
	}

	return head
}

//
// [2,4,3]
// [5,6,4]
//
// [7,0,8]
// TestaddTwoNumbers a
//
func TestAddTwoNumbers(t *testing.T) {

	data := []_node{
		_node{
			L1:     []int{2, 4, 3},
			L2:     []int{5, 6, 4},
			Expect: []int{7, 0, 8},
		},
		_node{
			L1:     []int{5},
			L2:     []int{5},
			Expect: []int{0, 1},
		},
		_node{
			L1:     []int{1, 8},
			L2:     []int{0},
			Expect: []int{1, 8},
		},
	}

	for i := range data {
		head1 := arrToList(data[i].L1)
		head2 := arrToList(data[i].L2)
		expect := arrToList(data[i].Expect)

		ret := addTwoNumbers(head1, head2)

		if ret == nil {
			t.Errorf("ret is null")
		}

		point1 := ret
		point2 := expect

		for {
			if point1 == nil && point2 == nil {
				break
			}

			if point1 == nil {
				if point2 != nil {
					t.Error("A")
					break
				}
			}

			if point2 == nil {
				if point1 != nil {
					t.Error("B")
					break
				}
			}

			if point1.Val != point2.Val {
				t.Errorf("%d != %d", point1.Val, point2.Val)
			}

			point1 = point1.Next
			point2 = point2.Next
		}
	}
}
