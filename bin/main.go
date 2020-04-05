package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	a := [][]int{[]int{1, 2}, []int{2, 3}}
	b := [][]int{[]int{2, 1}, []int{3, 2}}

	fmt.Println(compare(a, b))
}

func compare(a, b [][]int) bool  {
	if len(a) != len(b) {
		return false
	}

	for _, v := range a {
		sort.Ints(v)
	}

	for _, v := range b {
		sort.Ints(v)
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	sort.Slice(b, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})

	return reflect.DeepEqual(a, b)
}