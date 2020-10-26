package main

import (
	"fmt"
	_46_lru_cache "leetcode/main/146-lru-cache"
)

func main() {
	fmt.Println("Main")
	lru := _46_lru_cache.Constructor(3)
	lru.Put(1, 1)
	lru.Put(2, 2)
	lru.Put(3, 3)
	lru.Put(4, 4)
	lru.Put(5, 5)
	lru.Put(6, 6)
	lru.Put(7, 7)
	lru.Put(8, 8)
	lru.Print("")
}
