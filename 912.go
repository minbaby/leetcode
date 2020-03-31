package leetcode

func sortArray(nums []int) []int {
	quickSort(nums, 0, len(nums)-1)
	return nums
}

func quickSort(nums []int, low int, high int) {
	if low >= high {
		return
	}

	key := p(nums, low, high)
	quickSort(nums, low, key)
	quickSort(nums, key+1, high)
}

func p(nums []int, low int, high int) int {
	key := nums[low]

	for low < high {
		// 指针左移动
		for low < high && nums[high] > key {
			high--
		}
		for low < high && nums[low] < key {
			low++
		}

		if low != high && nums[low] == nums[high] {
			high--
			//low++
		}

		if low != high {
			nums[low], nums[high] = nums[high], nums[low]
		}
	}

	return low
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
