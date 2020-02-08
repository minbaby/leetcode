package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	var tmp *ListNode

	tmp1 := l1
	tmp2 := l2
	i := false
	j := 0

	for {
		if tmp1 == nil || tmp2 == nil {
			break
		}
		j = 0
		if i {
			j = 1
			i = false
		}
		j = tmp1.Val + tmp2.Val + j
		if j >= 10 {
			j = j - 10
			i = true
		}
		if head == nil {
			head = &ListNode{
				Val: j,
			}
			tmp = head
		} else {
			node := &ListNode{
				Val: j,
			}

			tmp.Next = node
			tmp = node
		}
		tmp1 = tmp1.Next
		tmp2 = tmp2.Next
	}

	for tmp1 != nil {
		j = 0
		if i {
			j = 1
			i = false
		}
		j = tmp1.Val + j
		if j >= 10 {
			j = j - 10
			i = true
		}
		if head == nil {
			head = &ListNode{
				Val: j,
			}
			tmp = head
		} else {
			node := &ListNode{
				Val: j,
			}

			tmp.Next = node
			tmp = node
		}
		tmp1 = tmp1.Next
	}

	for tmp2 != nil {
		j := 0
		if i {
			j = 1
			i = false
		}
		j = tmp2.Val + j
		if j >= 10 {
			j = j - 10
			i = true
		}
		if head == nil {
			head = &ListNode{
				Val: j,
			}
			tmp = head
		} else {

			node := &ListNode{
				Val: j,
			}

			tmp.Next = node
			tmp = node
		}
		tmp2 = tmp2.Next
	}

	if i {
		node := &ListNode{
			Val: 1,
		}
		tmp.Next = node
		tmp = node
	}

	return head
}
