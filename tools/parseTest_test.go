package tools

import (
	"reflect"
	"testing"
)

func TestParseOp(t *testing.T) {
	type args struct {
		str string
	}
	tests := []struct {
		name    string
		args    args
		want    []string
		wantErr bool
	}{
		{
			`["LRUCache","put","put","get","put","get","put","get","get","get"]`,
			args{
				str: `["LRUCache","put","put","get","put","get","put","get","get","get"]`,
			},
			[]string{
				"LRUCache",
				"put",
				"put",
				"get",
				"put",
				"get",
				"put",
				"get",
				"get",
				"get",
			},
			false,
		},
		{
			`error`,
			args{
				str: "",
			},
			nil,
			true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, err := ParseOp(tt.args.str)
			if (err != nil) != tt.wantErr {
				t.Errorf("ParseOp() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("ParseOp() got = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestParseParam(t *testing.T) {
	type args struct {
		str string
	}
	tests := []struct {
		name    string
		args    args
		want    [][]int
		wantErr bool
	}{
		{
			"[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]",
			args{
				str: "[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]",
			},
			[][]int{
				{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4},
			},
			false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, err := ParseParam(tt.args.str)
			if (err != nil) != tt.wantErr {
				t.Errorf("ParseParam() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("ParseParam() got = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestParseWant(t *testing.T) {
	type args struct {
		str string
	}
	tests := []struct {
		name    string
		args    args
		want    []interface{}
		wantErr bool
	}{
		{
			"[null,null,null,1,null,-1,null,-1,3,4]",
			args{
				"[null,null,null,1,null,-1,null,-1,3,4]",
			},
			[]interface{}{
				nil,
				nil,
				nil,
				1.0,
				nil,
				-1.0,
				nil,
				-1.0,
				3.0,
				4.0,
			},
			false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, err := ParseWant(tt.args.str)
			if (err != nil) != tt.wantErr {
				t.Errorf("ParseWant() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("ParseWant() got = %v, want %v", got, tt.want)
			}
		})
	}
}
