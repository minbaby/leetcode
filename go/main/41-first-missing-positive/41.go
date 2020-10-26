package _1_first_missing_positive

// firstMissingPositive 时间复杂度 O(N), 空间复杂度 O(1)
func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); i++ {
		// 正确位置，不需要处理
		if i+1 == nums[i] {
			continue
		}

		x := nums[i]
		if x >= 1 && x < len(nums) && x != nums[x-1] {
			nums[i], nums[x-1] = nums[x-1], nums[i]
			//抵消上面的i++，如果交换之后就不++；
			i--
		}

	}

	for i := 0; i < len(nums); i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}

	return len(nums) + 1
}

// firstMissingPositive_O2 双循环，时间复杂度 O(N^2)， 空间复杂度 O(1)
func firstMissingPositive_O2(nums []int) int {
	for i := 1; i <= len(nums); i++ {
		has := false
		for _, v := range nums {
			if i == v {
				has = true
				break
			}
		}
		if !has {
			return i
		}
	}

	return len(nums) + 1
}

// firstMissingPositive_O3 时间复杂度 O(N), 空间复杂度 O(N)
func firstMissingPositive_O3(nums []int) int {
	m := make(map[int]bool, len(nums))

	for _, v := range nums {
		m[v] = true
	}

	for i := 1; i <= len(nums); i++ {
		if _, ok := m[i]; !ok {
			return i
		}
	}

	return len(nums) + 1
}
