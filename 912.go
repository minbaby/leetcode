package leetcode

// 双向冒泡 or 鸡尾酒🍸排序
func sortArray(nums []int) []int {
	l := len(nums)

	low := 0
	high := l - 1

	for low < high {
		for i := low; i < high; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
			}
		}
		high--

		for i := high; i >= low; i-- {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
			}
		}
		low++
	}

	return nums
}

// 双向冒泡 or 鸡尾酒🍸排序
func sortArray2(nums []int) []int {
	l := len(nums)

	low := 0
	high := l - 1

	for low < high {
		for i := low; i < high; i++ {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
			}
		}
		high--

		for i := high; i >= low; i-- {
			if nums[i] > nums[i+1] {
				nums[i], nums[i+1] = nums[i+1], nums[i]
			}
		}
		low++
	}

	return nums
}

// 冒泡
func sortArray1(nums []int) []int {
	l := len(nums)

	for i := l; i > 0; i-- {
		for j := 0; j < i-1; j++ {
			if nums[j] > nums[j+1] {
				nums[j+1], nums[j] = nums[j], nums[j+1]
			}
		}
	}

	return nums
}
