package _6_24_pairs_with_sum

import "math"

func pairSums(nums []int, target int) [][]int {
	ret := [][]int{}

	m := map[int]int{}

	var v int
	var vv int
	for i := 0; i < len(nums); i++ {
		v = nums[i]
		vv = m[target-v]
		if vv >= 1 {
			m[target-v]--
			ret = append(ret, []int{v, target - v})
		} else {
			m[v]++
		}
	}

	return ret
}

// 低效方式
func pairSums0(nums []int, target int) [][]int {
	ret := [][]int{}

	l := len(nums)
	for i := 0; i < l; i++ {
		t := target - nums[i]
		if nums[i] == math.MinInt32 {
			continue
		}
		for j := i + 1; j < l; j++ {
			if nums[j] == math.MinInt32 {
				continue
			}
			if t == nums[j] {
				a, b := nums[i], nums[j]
				if a > b {
					a, b = b, a
				}
				ret = append(ret, []int{a, b})
				nums[j] = math.MinInt32
				break
			}
		}

		nums[i] = math.MinInt32
	}

	l = len(ret)

	for i := l; i >= 0; i-- {
		for j := i; j < l-1; j++ {
			if ret[j][0] > ret[j+1][0] {
				ret[j], ret[j+1] = ret[j+1], ret[j]
			}
		}
	}

	return ret
}
