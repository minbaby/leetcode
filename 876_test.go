package leetcode

import (
	"reflect"
	"testing"
)

func Test_middleNode(t *testing.T) {
	type args struct {
		head *ListNode876
	}
	tests := []struct {
		name string
		args args
		want *ListNode876
	}{
		{
			name: "[1,2,3,4,5]",
			args: args{
				&ListNode876{
					Val: 1,
					Next: &ListNode876{
						Val: 2,
						Next: &ListNode876{
							Val: 3,
							Next: &ListNode876{
								Val: 4,
								Next: &ListNode876{
									Val:  5,
									Next: nil,
								},
							},
						},
					},
				},
			},
			want: &ListNode876{
				Val: 3,
				Next: &ListNode876{
					Val: 4,
					Next: &ListNode876{
						Val:  5,
						Next: nil,
					},
				},
			},
		},
		{
			name: "[1,2,3,4,5,6]",
			args: args{
				&ListNode876{
					Val: 1,
					Next: &ListNode876{
						Val: 2,
						Next: &ListNode876{
							Val: 3,
							Next: &ListNode876{
								Val: 4,
								Next: &ListNode876{
									Val: 5,
									Next: &ListNode876{
										Val:  6,
										Next: nil,
									},
								},
							},
						},
					},
				},
			},
			want: &ListNode876{
				Val: 4,
				Next: &ListNode876{
					Val: 5,
					Next: &ListNode876{
						Val:  6,
						Next: nil,
					},
				},
			},
		},
		{
			name: "[]",
			args: args{},
			want: nil,
		},
		{
			name: "[1]",
			args: args{&ListNode876{
				Val:  1,
				Next: nil,
			}},
			want: &ListNode876{
				Val:  1,
				Next: nil,
			},
		},
		{
			name: "[1,2]",
			args: args{&ListNode876{
				Val: 1,
				Next: &ListNode876{
					Val:  2,
					Next: nil,
				},
			}},
			want: &ListNode876{
				Val:  2,
				Next: nil,
			},
		},
		{
			name: "[1,2,3]",
			args: args{&ListNode876{
				Val: 1,
				Next: &ListNode876{
					Val: 2,
					Next: &ListNode876{
						Val:  3,
						Next: nil,
					},
				},
			}},
			want: &ListNode876{
				Val: 2,
				Next: &ListNode876{
					Val:  3,
					Next: nil,
				},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := middleNode(tt.args.head); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("middleNode() = %v, want %v", got, tt.want)
			}
		})
	}
}
