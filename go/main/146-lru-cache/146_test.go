package _46_lru_cache

import (
	"fmt"
	"leetcode/tools"
	"testing"
)

const (
	LRUCacheConstructor = iota
	Put
	Get
)

const _debug = false

func TestLogic1(t *testing.T) {
	strOp := `["LRUCache","put","put","get","put","get","put","get","get","get"]`
	strParam := `[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]`
	strWant := `[null,null,null,1,null,-1,null,-1,3,4]`
	runLogic(t, strOp, strParam, strWant)
}

func TestLogic2(t *testing.T) {
	strOp := `["LRUCache","put","put","get","put","get","get"]`
	strParam := `[[2],[2,1],[1,1],[2],[4,1],[1],[2]]`
	strWant := `[null,null,null,1,null,-1,1]`
	runLogic(t, strOp, strParam, strWant)
}

func TestLogic3(t *testing.T) {
	strOp := `["LRUCache","put","put","get","put","put","get"]`
	strParam := `[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]`
	strWant := `[null,null,null,2,null,null,-1]`
	runLogic(t, strOp, strParam, strWant)
}

func TestLogic4(t *testing.T) {
	strOp := `["LRUCache","get","put","get","put","put","get","get"]`
	strParam := `[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]`
	strWant := `[null,-1,null,-1,null,null,2,6]`
	runLogic(t, strOp, strParam, strWant)
}

func TestLogic5(t *testing.T) {
	strOp := `["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]`
	strParam := `[[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]`
	strWant := `[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]`
	runLogic(t, strOp, strParam, strWant)
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
	var instance LRUCache

	for i, v := range opList {
		if v == "LRUCache" {
			instance = Constructor(argList[i][0])
			if _debug {
				instance.Print("LRUCacheConstructor")
			}
		} else if v == "get" {
			got := instance.Get(argList[i][0])
			if _debug {
				instance.Print(fmt.Sprintf("[%v] Get(%d)", i, argList[i][0]))
			}
			if want := int(wantList[i].(float64)); got != want {
				t.Errorf("[%v] Get(%v) = %v, want %v", i, argList[i][0], got, want)
			}
		} else if v == "put" {
			instance.Put(argList[i][0], argList[i][1])
			if _debug {
				instance.Print(fmt.Sprintf("[%v] Put(%d, %d)", i, argList[i][0], argList[i][1]))
			}
		} else {
			t.Errorf("unkown op: %s", v)
		}
	}
}
