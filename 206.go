package leetcode

func reverseList(head *ListNode) *ListNode {

	var tail *ListNode

	point := head
	var tmp *ListNode
	for point != nil && point.Next != nil {

		if tail == nil {
			tail = point
		} else {
			tmp = tail
			tail = point
			tail.Next = tmp
		}

		point = point.Next
	}

	return tail
}
