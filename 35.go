package leetcode

func searchInsert(nums []int, target int) int {
	l := len(nums)
	for i := 0; i < l; i++ {
		if nums[i] >= target {
			return i
		}

	}

	return l
}

func searchInsert2(nums []int, target int) int {
	h := len(nums)
	l := 0

	for l < h {
		mid := (l + h) / 2 // l + (h-l)/2

		if nums[mid] > target {
			h = mid
		} else if nums[mid] < target {
			l = mid + 1
		} else {
			return mid
		}
	}

	return l
}
