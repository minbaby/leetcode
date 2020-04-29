package _1_container_with_most_water

// 最笨的方法， 遍历
func maxArea(height []int) int {
	l := len(height)
	max := 0
	for i := 0; i < l; i++ {
		for j := i; j < l; j++ {
			t := min(height[i], height[j]) * (j - i)
			if t > max {
				max = t
			}
		}
	}
	return max
}

func min(i, j int) int {
	if i > j {
		return j
	}

	return i
}
