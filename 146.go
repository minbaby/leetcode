package leetcode

type LRUCache struct {
	capacity int
	len int
	head *node
	tail *node
}

type node struct {
	prev *node
	next *node
	val int
}

func Constructor(capacity int) LRUCache {
	head := &node{}
	tail := &node{}
	head.next = tail
	tail.prev = head
	return LRUCache{
		capacity: capacity,
		len:      0,
		head:     head,
		tail:     tail,
	}
}
//
//
//func (this *LRUCache) Get(key int) int {
//
//}
//
//
//func (this *LRUCache) Put(key int, value int)  {
//
//}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
