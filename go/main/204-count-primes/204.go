package _04_count_primes

// 基本思路， 把能整除2的删掉，整除3的删掉，整除5的删掉。。。。, 每次步进为第i个数
func countPrimes(n int) int {
	b := make([]bool, n)

	for i := 2; i < n; i++ {
		b[i] = true
	}

	for i := 2; i*i < n; i++ {
		if !b[i] {
			continue
		}

		for j := i * i; j < n; j += i {
			if j%i == 0 {
				b[j] = false
			}
		}
	}

	c := 0
	for _, v := range b {
		if v {
			c++
		}
	}
	return c
}

// 基本思路， 把能整除2的删掉，整除3的删掉，整除5的删掉。。。。,需要优化
func countPrimes3(n int) int {
	b := make([]bool, n)

	for i := 2; i < n; i++ {
		b[i] = true
	}

	for i := 2; i < n; i++ {
		if b[i] == false {
			continue
		}

		for j := i * i; j < n; j++ {
			if j%i == 0 {
				b[j] = false
			}
		}
	}

	c := 0
	for _, v := range b {
		if v {
			c++
		}
	}
	return c
}

// M^2 速度有点慢。。。
func countPrimes2(n int) int {
	if n < 3 {
		return 0
	}
	if n == 3 {
		return 1
	}

	m := []int{
		2,
		3,
	}

	for i := 4; i < n; i++ {
		b := false
		for _, v := range m {
			if i%v == 0 {
				b = true
				break
			}
		}
		if !b {
			m = append(m, i)
		}
	}
	return len(m)
}
