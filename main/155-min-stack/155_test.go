package _55_min_stack

import (
	"fmt"
	"leetcode/tools"
	"testing"
)

const _debug = false

func TestXXX(t *testing.T) {
	runLogic(
		t,
		`["MinStack","push","push","push","getMin","pop","top","getMin"]`,
		`[[],[-2],[0],[-3],[],[],[],[]]`,
		`[null,null,null,null,-3,null,0,-2]`,
	)
}

func TestYYY(t *testing.T) {
	runLogic(
		t,
		`["MinStack","push","push","top","getMin","pop","getMin","top"]`,
		`[[],[1],[2],[],[],[],[],[]]`,
		`[null,null,null,2,1,null,1,1]`,
	)
}

func TestZZZ(t *testing.T) {
	runLogic(
		t,
		`["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]`,
		`[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]`,
		`[null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483648,-2147483648,null,2147483647]`,
	)
}

func runLogic(t *testing.T, strOp, strParam, strWant string) {
	var err error
	var opList []string
	if opList, err = tools.ParseOp(strOp); err != nil {
		t.Error(err)
	}

	var argList [][]int
	if argList, err = tools.ParseParam(strParam); err != nil {
		t.Error(err)
	}

	var wantList []interface{}
	if wantList, err = tools.ParseWant(strWant); err != nil {
		t.Error(err)
	}
	var instance MinStack

	for i, v := range opList {
		if v == "MinStack" {
			instance = Constructor()
			if _debug {
				instance.Print("MinStack Constructor")
			}
		} else if v == "pop" {
			instance.Pop()
			if _debug {
				instance.Print(fmt.Sprintf("[%v] Pop()", i))
			}
		} else if v == "top" {
			got := instance.Top()
			if want := int(wantList[i].(float64)); got != want {
				t.Errorf("[%v] Top(%v) = %v, want %v", i, argList[i][0], got, want)
			}
		} else if v == "getMin" {
			got := instance.GetMin()
			if want := int(wantList[i].(float64)); got != want {
				t.Errorf("[%v] GetMin(%v) = %v, want %v", i, argList[i][0], got, want)
			}
		} else if v == "push" {
			instance.Push(argList[i][0])
			if _debug {
				instance.Print(fmt.Sprintf("[%v] Push(%d)", i, argList[i][0]))
			}
		} else {
			t.Errorf("unkown op: %s", v)
		}
	}
}
