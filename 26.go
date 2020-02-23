package leetcode

func removeDuplicates(nums []int) int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); {
			if nums[i] == nums[j] {
				nums = append(nums[:j], nums[j+1:]...)
			} else {
				j++
			}
		}
	}

	return len(nums)
}
