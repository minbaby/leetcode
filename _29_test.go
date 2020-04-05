package leetcode

import "testing"

func Test_divide(t *testing.T) {
	type args struct {
		dividend int
		divisor  int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
				"10,3",
				args{10, 3},
				3,
		},
		{
			"7,-3",
			args{7, -3},
			-2,
		},
		{
			"-2147483648 -1",
			args{-2147483648, -1},
			2147483647,
		},
		{
			"-2147483648 1",
			args{-2147483648, 1},
			-2147483648,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := divide(tt.args.dividend, tt.args.divisor); got != tt.want {
				t.Errorf("divide() = %v, want %v", got, tt.want)
			}
		})
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := divide2(tt.args.dividend, tt.args.divisor); got != tt.want {
				t.Errorf("divide() = %v, want %v", got, tt.want)
			}
		})
	}
}
