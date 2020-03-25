package leetcode

func middleNode(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	if head.Next.Next == nil {
		return head.Next
	}

	tmp := head
	tmp2 := head
	for tmp2 != nil && tmp2.Next != nil {
		tmp = tmp.Next
		tmp2 = tmp2.Next.Next
	}
	return tmp
}
