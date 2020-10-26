package _1_merge_two_sorted_lists

import (
	"encoding/json"
	"reflect"
	"testing"
)

func Test_mergeTwoLists(t *testing.T) {
	type args struct {
		l1 *ListNode
		l2 *ListNode
	}
	tests := []struct {
		name string
		args args
		want *ListNode
	}{
		{
			"[1,2,4]\n[1,3,4]",
			args{
				parseList21(`[1,2,4]`),
				parseList21(`[1,3,4]`),
			},
			parseList21(`[1,1,2,3,4,4]`),
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := mergeTwoLists(tt.args.l1, tt.args.l2); !reflect.DeepEqual(got, tt.want) {
				tt.want.Print()
				got.Print()
				t.Errorf("mergeTwoLists() = %v, want %v", got, tt.want)
			}
		})
	}
}

func parseList21(str string) *ListNode {
	var data []int
	_ = json.Unmarshal([]byte(str), &data)

	head := &ListNode{data[0], nil}
	p := head
	for i := 1; i < len(data); i++ {
		node := &ListNode{
			Val:  data[i],
			Next: nil,
		}
		p.Next = node
		p = p.Next
	}

	return head
}
