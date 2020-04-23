package __string_to_integer_atoi

import "testing"

func Test_myAtoi(t *testing.T) {
	type args struct {
		str string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"42",
			args{"42"},
			42,
		},
		{
			"-42",
			args{"-42"},
			-42,
		},
		{
			"4193 with words",
			args{"4193 with words"},
			4193,
		},
		{
			"words and 987",
			args{"words and 987"},
			0,
		},
		{
			"-91283472332",
			args{"-91283472332"},
			-2147483648,
		},
		{
			" ",
			args{" "},
			0,
		},
		{
			"+1",
			args{"+1"},
			1,
		},
		{
			"2147483646",
			args{"2147483646"},
			2147483646,
		},
		{
			"9223372036854775808",
			args{"9223372036854775808"},
			2147483647,
		},
		{
			"  0000000000012345678",
			args{"  0000000000012345678"},
			12345678,
		},
		{
			"010",
			args{"010"},
			10,
		},
		{
			"-2147483647",
			args{"-2147483647"},
			-2147483647,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := myAtoi(tt.args.str); got != tt.want {
				t.Errorf("myAtoi() = %v, want %v", got, tt.want)
			}
		})
	}
}
