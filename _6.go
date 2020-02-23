package leetcode

import "fmt"

//
// 1. 完整列，每间隔 numRows - 2，出现一次
// 2. 完整列 0 - numRows
//
func convert(s string, numRows int) string {
	l := len(s)
	data := make([][]byte, numRows)
	for i := 0; i < numRows; i++ {
		data[i] = make([]byte, l)
	}

	idx := 0
	ii := 0
	for {
		if idx >= l {
			break
		}

		x := idx % numRows
		fmt.Println(x)
		if x == 0 {
			for i := 0; i < numRows; i++ {
				data[i][x] = s[ii]
				ii++
			}
		} else {
			data[numRows-idx-1][x] = s[ii]
			ii++
		}
		idx++

	}

	// 1, numRows-1

	for _, y := range data {
		for _, z := range y {
			fmt.Print(string(z) + "   ")
		}
		fmt.Println()
	}

	return ""
}
