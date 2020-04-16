package leetcode

type MinStack struct {
	Val    []int
	MinVal int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	if this.Val == nil {
		this.MinVal = x
	} else if x < this.MinVal {
		this.MinVal = x
	}
	this.Val = append(this.Val, x)
}

func (this *MinStack) Pop() {
	if this.Val == nil {
		return
	}

	l := len(this.Val)

	if l == 1 {
		this.Val = nil
		return
	}

	p := this.Val[l-1]
	this.Val = this.Val[:l-1]
	if p <= this.MinVal {
		this.MinVal = this.Val[0]
		for _, v := range this.Val {
			if v < this.MinVal {
				this.MinVal = v
			}
		}
	}
}

func (this *MinStack) Top() int {
	l := len(this.Val)
	return this.Val[l-1]
}

func (this *MinStack) GetMin() int {
	return this.MinVal
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
