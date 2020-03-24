package leetcode

func massage(nums []int) int {

	if len(nums) == 0 {
		return 0
	}

	yMax, nMax := nums[0], 0

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	for i := 1; i < len(nums); i++ {
		tYMax, tNMax := 0, 0
		tNMax = max(yMax, nMax)
		tYMax = nMax + nums[i]

		yMax = tYMax
		nMax = tNMax
	}

	return max(yMax, nMax)
}
