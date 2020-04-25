package _1_shu_zu_zhong_de_ni_xu_dui_lcof

func reversePairs(nums []int) int {
	ret := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] > nums[j] {
				ret++
			}
		}
	}
	return ret
}

// 笨方法，双循环
func reversePairs1(nums []int) int {
	ret := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] > nums[j] {
				ret++
			}
		}
	}
	return ret
}
