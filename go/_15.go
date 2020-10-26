package leetcode

func threeSum(nums []int) [][]int {
	ret := [][]int{}
	l := len(nums)
	for i := 0; i < l; i++ {
		for j := i + 1; j < l; j++ {
			for k := j + 1; k < l; k++ {
				if nums[i]+nums[j]+nums[k] != 0 {
					continue
				}
				tmp := []int{
					nums[i],
					nums[j],
					nums[k],
				}

				if has(tmp, ret) {
					break
				}
				ret = append(ret, tmp)
			}
		}
	}

	return ret
}

func isEqual(a, b []int) bool {
	if (a == nil) != (b == nil) {
		return false
	}

	if len(a) != len(b) {
		return false
	}

	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}
