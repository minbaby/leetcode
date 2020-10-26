package _095_find_in_mountain_array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */
type MountainArray struct {
	data  []int
	Count int
}

func New(data []int) *MountainArray {
	return &MountainArray{
		data:  data,
		Count: 0,
	}
}

func (this *MountainArray) get(index int) int {
	this.Count++
	return this.data[index]
}

func (this *MountainArray) length() int {
	return len(this.data)
}

//思路，先找到最大值，然后再搜索两边的值。二分法
func findInMountainArray(target int, mountainArr *MountainArray) int {
	left := 0
	right := mountainArr.length()

	maxIndex := 0
	for left < right {
		mid := (right-left)/2 + left
		mData := mountainArr.get(mid)
		lData := mountainArr.get(mid - 1)
		rData := mountainArr.get(mid + 1)
		if mData > lData && mData > rData {
			maxIndex = mid
			break
		} else if mData > lData && mData < rData {
			//处于增区间
			left = mid
		} else {
			// 减区间
			right = mid
		}
	}

	// 0-maxIndex 有没有
	left = 0
	right = maxIndex
	for left < right {
		mid := (right-left)/2 + left
		mData := mountainArr.get(mid)
		if mData > target {
			right = mid
		} else if mData < target {
			left = mid + 1
		} else {
			return mid
		}
	}

	//maxIndex-len 有没有
	left = maxIndex
	right = mountainArr.length()
	for left < right {
		mid := (right-left)/2 + left
		mData := mountainArr.get(mid)
		if mData < target {
			right = mid
		} else if mData > target {
			left = mid + 1
		} else {
			return mid
		}
	}

	return -1
}
