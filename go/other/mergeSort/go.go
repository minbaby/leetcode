package mergeSort

func mergeSort(nums []int) []int {
	l := len(nums)

	if l <= 1 {
		return nums
	}

	mid := l / 2

	left := mergeSort(nums[:mid])
	right := mergeSort(nums[mid:])

	ret := make([]int, l)

	i, j, k := 0, 0, 0
	for true {
		if i >= len(left) && j >= len(right) {
			break
		}

		if i < len(left) && j < len(right) {
			if left[i] < right[j] {
				ret[k] = left[i]
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
				j++
				k++
			}
		}
	}

	return ret
}
