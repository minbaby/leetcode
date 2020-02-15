package leetcode

import "testing"

func Test_reverse(t *testing.T) {
	type args struct {
		x int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
		{
			"123",
			args{123},
			321,
		},
		{
			"-123",
			args{-123},
			-321,
		},
		{
			"120",
			args{120},
			21,
		},
		{
			"1534236469",
			args{1534236469},
			0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := reverse(tt.args.x); got != tt.want {
				t.Errorf("reverse() = %v, want %v", got, tt.want)
			}
		})
	}
}
