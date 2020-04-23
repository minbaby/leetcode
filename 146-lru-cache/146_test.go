package _46_lru_cache

import (
	"testing"
)

const (
	LRUCacheConstructor = iota
	Put
	Get
)

const _debug = true

func TestLogic0(t *testing.T) {
	opList := []int{
		LRUCacheConstructor,
		Put,
		Get,
		Get,
	}

	argList := [][]int{
		{
			2,
		},
		{
			1,
			1,
		},
		{
			4,
		},
		{
			1,
		},
	}

	wantList := []interface{}{
		nil,
		nil,
		-1,
		1,
	}

	runLogic(t, opList, argList, wantList)
}

func TestLogic1(t *testing.T) {
	opList := []int{
		LRUCacheConstructor,
		Put,
		Put,
		Put,
		Get,
	}

	argList := [][]int{
		{
			2,
		},
		{
			1,
			2,
		},
		{
			2,
			3,
		},
		{
			3,
			4,
		},
		{
			2,
		},
	}

	wantList := []interface{}{
		nil,
		nil,
		nil,
		nil,
		3,
	}

	runLogic(t, opList, argList, wantList)
}

func TestLogic2(t *testing.T) {
	opList := []int{
		LRUCacheConstructor,
		Put,
		Put,
		Get,
		Put,
		Get,
		Put,
		Get,
		Get,
		Get,
	}

	argList := [][]int{
		{
			2,
		},
		{
			1,
			1,
		},
		{
			2,
			2,
		},
		{
			1,
		},
		{
			3,
			3,
		},
		{
			2,
		},
		{
			4,
			4,
		},
		{
			1,
		},
		{
			3,
		},
		{
			4,
		},
	}

	wantList := []interface{}{
		nil,
		nil,
		nil,
		1,
		nil,
		2,
		nil,
		-1,
		3,
		4,
	}

	runLogic(t, opList, argList, wantList)
}

func runLogic(t *testing.T, opList []int, argList [][]int, wantList []interface{}) {
	var instance LRUCache
	for i, v := range opList {
		if v == LRUCacheConstructor {
			instance = Constructor(argList[i][0])
			if _debug {
				instance.Print()
			}
		} else if v == Get {
			got := instance.Get(argList[i][0])
			if _debug {
				instance.Print()
			}
			if got != wantList[i] {
				t.Errorf("[%v] Get(%v) = %v, want %v", i, argList[i][0], got, wantList[i])
			}
		} else if v == Put {
			instance.Put(argList[i][0], argList[i][1])
			if _debug {
				instance.Print()
			}
		} else {
			t.Errorf("unkown op: %d", v)
		}
	}
}
