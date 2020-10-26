package leetcode

import "testing"

func Test_new21Game(t *testing.T) {
	type args struct {
		N int
		K int
		W int
	}
	tests := []struct {
		name string
		args args
		want float64
	}{
		{
			name: "10,1,10",
			args: args{
				N: 10,
				K: 1,
				W: 10,
			},
			want: 1.0,
		},
		{
			name: "6,1,10",
			args: args{
				N: 6,
				K: 1,
				W: 10,
			},
			want: 0.6,
		},
		{
			name: "21,17,10",
			args: args{
				N: 21,
				K: 17,
				W: 10,
			},
			want: 0.73278,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := new21Game(tt.args.N, tt.args.K, tt.args.W); got != tt.want {
				t.Errorf("new21Game() = %v, want %v", got, tt.want)
			}
		})
	}
}
