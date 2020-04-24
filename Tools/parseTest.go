package Tools

import "encoding/json"

func ParseOp(str string) ([]string, error) {
	var op []string
	err := json.Unmarshal([]byte(str), &op)
	if err != nil {
		return nil, err
	}

	return op, nil
}

func ParseParam(str string) ([][]int, error) {
	var param [][]int
	err := json.Unmarshal([]byte(str), &param)
	if err != nil {
		return nil, err
	}

	return param, nil
}

func ParseWant(str string) ([]interface{}, error) {
	var want []interface{}
	err := json.Unmarshal([]byte(str), &want)
	if err != nil {
		return nil, err
	}

	return want, nil
}

func ParseIntArray(str string) []int {
	var ret []int
	err := json.Unmarshal([]byte(str), &ret)
	if err != nil {
		return nil
	}

	return ret
}
