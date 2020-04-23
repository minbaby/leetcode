package _46_lru_cache

import "fmt"

type LRUCache struct {
	capacity int
	len      int
	head     *node
	tail     *node
	data     map[int]*node
}

type node struct {
	prev *node
	next *node
	val  int
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
		data:     map[int]*node{},
	}
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.data[key]; ok == true {
		// TODO: move to first
		p := this.head
		for p.next != nil {
			if p.val == v.val {
				break
			} else {
				p = p.next
			}
		}
		return v.val
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if n, ok := this.data[key]; ok == true {
		// remove {n} from list
		n.prev.next = n.next
		n.next.prev = n.prev

		// add {n} to list head
		this.head.next.prev = n
		n.next = this.head.next
		this.head.next = n
		n.prev = this.head

	} else {
		// capacity
		n = &node{val: value}
		if this.len >= this.capacity {
			this.tail.prev.prev = n
			n.next = this.tail
			n.prev = this.tail.prev
			this.tail.prev = n
		} else {
			this.tail.prev.next = n
			n.next = this.tail
			n.prev = this.tail
			this.tail.prev = n
		}
		this.data[key] = n
	}
}

func (this *LRUCache) Print() {
	p := this.head
	for p != nil {
		fmt.Printf("%v --> ", p)
		p = p.next
	}
	fmt.Println()
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
