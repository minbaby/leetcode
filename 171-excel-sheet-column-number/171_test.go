package _71_excel_sheet_column_number

import "testing"

func Test_titleToNumber(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			"A",
			args{"A"},
			1,
		},
		{
			"AB",
			args{"AB"},
			28,
		},
		{
			"ZY",
			args{"ZY"},
			701,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := titleToNumber(tt.args.s); got != tt.want {
				t.Errorf("titleToNumber() = %v, want %v", got, tt.want)
			}
		})
		t.Run(tt.name+"#2", func(t *testing.T) {
			if got := titleToNumber2(tt.args.s); got != tt.want {
				t.Errorf("titleToNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
