package _1_merge_two_sorted_lists

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	p1, p2 := l1, l2
	head := &ListNode{}
	p := head
	for p1 != nil && p2 != nil {
		if p1.Val < p2.Val {
			p.Next = p1
			p1 = p1.Next
		} else {
			p.Next = p2
			p2 = p2.Next
		}
		p = p.Next
	}

	for p1 != nil {
		p.Next = p1
		p1 = p1.Next
		p = p.Next
	}

	for p2 != nil {
		p.Next = p2
		p2 = p2.Next
		p = p.Next
	}

	return head.Next
}

func (lst *ListNode) Print() {
	p := lst
	for p.Next != nil {
		fmt.Printf("v:%d\t", p.Val)
		p = p.Next
	}
	fmt.Println()
}
