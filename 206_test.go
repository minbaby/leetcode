package leetcode

import (
	"reflect"
	"testing"
)

func Test_reverseList(t *testing.T) {
	type args struct {
		head *ListNode
	}
	tests := []struct {
		name string
		args args
		want *ListNode
	}{
		{
			"1->2->3->4->5->NULL <> 5->4->3->2->1->NULL",
			args{
				head:
				&ListNode{
					1,
					&ListNode{
						Val:  2,
						Next: &ListNode{
							Val:  3,
							Next: &ListNode{
								Val:  4,
								Next: &ListNode{
									Val:  5,
									Next: nil,
								},
							},
						},
					},
				},
			},
			&ListNode{
				5,
				&ListNode{
					Val:  4,
					Next: &ListNode{
						Val:  3,
						Next: &ListNode{
							Val:  2,
							Next: &ListNode{
								Val:  1,
								Next: nil,
							},
						},
					},
				},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reverseList(tt.args.head); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("reverseList() = %v, want %v", got, tt.want)
			}
		})
	}
}
