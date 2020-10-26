package _2_01_remove_duplicate_node

import (
	"leetcode/tools"
	"reflect"
	"testing"
)

func Test_removeDuplicateNodes(t *testing.T) {
	type args struct {
		head *ListNode
	}
	tests := []struct {
		name string
		args args
		want *ListNode
	}{
		{
			name: "[1, 2, 3, 3, 2, 1]",
			args: args{
				head: ParseNodeList("[1,2,3,3,2,1]"),
			},
			want: ParseNodeList("[1, 2, 3]"),
		},
		{
			name: "[1, 1, 1, 1, 2]",
			args: args{
				head: ParseNodeList("[1, 1, 1, 1, 2]"),
			},
			want: ParseNodeList("[1, 2]"),
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := removeDuplicateNodes(tt.args.head); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("removeDuplicateNodes() = %v, want %v", got, tt.want)
			}
		})
	}
}

func ParseNodeList(str string) *ListNode {
	data := tools.ParseIntArray(str)
	head := &ListNode{
		Val: data[0],
	}
	p := head
	for i := 1; i < len(data); i++ {
		n := &ListNode{
			Val: data[i],
		}

		p.Next = n
		p = n
	}

	return head
}
