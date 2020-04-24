package _46_lru_cache

import (
	"fmt"
)

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
	key  int
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
	if this.capacity == 0 {
		return -1
	}

	if n, ok := this.data[key]; ok == true {
		this.removeNode(n)
		this.addToHead(n)
		return n.val
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if this.capacity == 0 {
		return
	}

	n := &node{val: value, key: key}
	if v, ok := this.data[key]; ok == true {
		this.removeNode(v)
		this.addToHead(n)
	} else {
		// capacity
		if this.len >= this.capacity {
			last := this.tail.prev
			this.removeNode(last)

			delete(this.data, last.key)
			this.len--
		}
		this.addToHead(n)
		this.len++
	}
	this.data[key] = n
}

func (this *LRUCache) Print(s string) {
	p := this.head
	c := 0
	fmt.Printf("[%s-1] ", s)
	for p != nil {
		fmt.Printf("[%v (%p)] => ", p, p)
		p = p.next
		c++
		if c > 100 {
			fmt.Println("\nloop max: ")
			break
		}
	}
	fmt.Println()
	fmt.Printf("[%s-2] %v", s, this.data)
	fmt.Println()
	fmt.Println()
}

func (this *LRUCache) removeNode(n *node) {
	n.prev.next = n.next
	n.next.prev = n.prev
}

func (this *LRUCache) addToHead(n *node) {
	// add {n} to list head
	this.head.next.prev = n
	n.next = this.head.next
	this.head.next = n
	n.prev = this.head
}
