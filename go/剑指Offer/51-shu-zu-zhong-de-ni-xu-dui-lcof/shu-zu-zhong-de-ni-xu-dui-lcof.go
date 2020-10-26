package _1_shu_zu_zhong_de_ni_xu_dui_lcof

func reversePairs(nums []int) int {
	_, ret := mergeSort(nums)
	return ret
}

func mergeSort(nums []int) ([]int, int) {
	l := len(nums)

	if l <= 1 {
		return nums, 0
	}

	mid := l / 2

	left, cLeft := mergeSort(nums[:mid])
	right, cRight := mergeSort(nums[mid:])

	ret := make([]int, l)

	count, i, j, k := 0, 0, 0, 0

	for true {
		if i >= len(left) && j >= len(right) {
			break
		} else if i < len(left) && j < len(right) {
			if left[i] > right[j] {
				ret[k] = left[i]
				count += len(right) - j
				i++
				k++
			} else {
				ret[k] = right[j]
				j++
				k++
			}
		} else {
			if i < len(left) {
				ret[k] = left[i]
				i++
				k++
			}

			if j < len(right) {
				ret[k] = right[j]
				k++
				j++
			}
		}
	}

	return ret, count + cLeft + cRight
}

// 笨方法，双循环
func reversePairs1(nums []int) int {
	ret := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] > nums[j] {
				ret++
			}
		}
	}
	return ret
}
