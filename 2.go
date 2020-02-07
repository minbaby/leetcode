package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}

	var head *ListNode
	var tmp *ListNode

	tmp1 := l1
	tmp2 := l2
	i := false

	for {
		j := 0

		if tmp1 == nil && tmp2 == nil {
			if i {
				node := &ListNode{
					Val: 1,
				}
				tmp.Next = node
				tmp = node
			}
			break
		}

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
				Val:  j,
				Next: nil,
			}
			tmp = head
		} else {

			node := &ListNode{
				Val:  j,
				Next: nil,
			}

			tmp.Next = node
			tmp = node
		}

		tmp1 = tmp1.Next
		tmp2 = tmp2.Next
	}

	return head
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
