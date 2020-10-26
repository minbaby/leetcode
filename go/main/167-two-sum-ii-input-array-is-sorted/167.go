package _67_two_sum_ii_input_array_is_sorted

func twoSum(numbers []int, target int) []int {
	index1, index2 := 0, len(numbers)-1

	for index1 < index2 {
		if numbers[index1]+numbers[index2] < target {
			index1++
			continue
		}

		if numbers[index1]+numbers[index2] > target {
			index2--
			continue
		}

		if numbers[index1]+numbers[index2] == target {
			return []int{index1 + 1, index2 + 1}
		}

	}

	return []int{-1, -1}
}

// 这个算是遍历法把
func twoSumMy(numbers []int, target int) []int {
	var ret []int
	index1, index2 := 0, 0
	for ; index1 < len(numbers); index1++ {
		need := target - numbers[index1]
		for index2 = index1 + 1; index2 < len(numbers); index2++ {
			if need == numbers[index2] {
				ret = append(ret, index1+1, index2+1)
				break
			}
		}
	}
	return ret
}
