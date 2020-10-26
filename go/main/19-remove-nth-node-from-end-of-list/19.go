package _9_remove_nth_node_from_end_of_list

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}

	d := &ListNode{Next: head}

	second := d
	first := d
	for i := 0; i <= n; i++ {
		first = first.Next
	}

	for first != nil {
		second = second.Next
		first = first.Next
	}

	second.Next = second.Next.Next

	return d.Next
}

func PrintList(head *ListNode) {
	p := head
	max := 100
	c := 0
	for p != nil {
		fmt.Print(p.Val, "\t")
		p = p.Next
		c++
		if c > max {
			break
		}
	}
	fmt.Println()
}
