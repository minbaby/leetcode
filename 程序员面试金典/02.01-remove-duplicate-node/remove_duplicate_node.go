package _2_01_remove_duplicate_node

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeDuplicateNodes(head *ListNode) *ListNode {
	isUsed := make(map[int]bool)
	p := &ListNode{
		Next: head,
	}

	for p.Next != nil {
		if _, ok := isUsed[p.Next.Val]; !ok {
			isUsed[p.Next.Val] = true
			p = p.Next
		} else {
			p.Next = p.Next.Next
		}
	}

	return head
}

const DEBUG = true

func (head *ListNode) Print() {
	p := head
	if DEBUG {
		fmt.Print("[")
	}
	for {
		if p == nil {
			break
		}
		if DEBUG {
			fmt.Printf("%d, ", p.Val)
		}
		p = p.Next
	}
	if DEBUG {
		fmt.Println("-]")
	}
}
