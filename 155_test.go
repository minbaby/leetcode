package leetcode

import (
	"fmt"
	"testing"
)

//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
func TestXXX(t *testing.T)  {
	m := Constructor()
	m.Push(-2)
	m.Push(0)
	m.Push(-3)
	fmt.Println(m.GetMin())
	fmt.Println(m.Top())
	m.Pop()
	fmt.Println(m.Top())
	fmt.Println(m.GetMin())
	fmt.Println(m.Val)
}

//["MinStack","push","push","top","getMin","pop","getMin","top"]
//[[],[1],[2],[],[],[],[],[]]
// [null,null,null,2,1,null,1,1]
func TestYYY(t *testing.T)  {
	m := Constructor()
	m.Push(1)
	m.Push(2)
	fmt.Println(m.Top())
	fmt.Println(m.GetMin())
	m.Pop()
	fmt.Println(m.GetMin())
	fmt.Println(m.Top())
	fmt.Println(m.Val)
}

//["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
//[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
func TestZZZ(t *testing.T)  {
	m := Constructor()
	m.Push(2147483646)
	m.Push(2147483646)
	m.Push(2147483647)
	fmt.Println(m.Top())
	m.Pop()
	fmt.Println(m.GetMin())
	m.Pop()
	fmt.Println(m.GetMin())
	m.Pop()
	m.Push(2147483647)
	fmt.Println(m.Top())
	fmt.Println(m.GetMin())
	m.Push(2147483647)
	fmt.Println(m.Top())
	fmt.Println(m.GetMin())
	m.Pop()
	fmt.Println(m.GetMin())
	fmt.Println(m.Val)
}