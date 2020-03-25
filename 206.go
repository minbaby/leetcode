package leetcode

func reverseList(head *ListNode) *ListNode {
	var tail *ListNode
	point := head
	var tmp *ListNode
	for point != nil {
		tmp = point.Next // 直接操作当前节点的化会导致无法找到下一个节点，所以这个地方做个保存
		point.Next = tail
		tail = point
		point = tmp
	}

	return tail
}
