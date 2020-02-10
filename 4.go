package leetcode

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	p1 := 0
	p2 := 0
	l1 := len(nums1)
	l2 := len(nums2)
	news := []int{}
	m := (l1 + l2) / 2

	for true {
		if p2 >= l2 || p1 >= l1 {
			break
		}
		if nums1[p1] > nums2[p2] {
			news = append(news, nums2[p2])
			p2++

		} else {
			news = append(news, nums1[p1])
			p1++
		}
	}

	for i := p1; i < l1; i++ {
		news = append(news, nums1[p1])
		p1++
	}

	for j := p2; j < l2; j++ {
		news = append(news, nums2[p2])
		p2++
	}

	if (l1+l2)%2 == 1 {
		return float64(news[m])
	}
	return float64(news[m-1]+news[m]) / 2
}
