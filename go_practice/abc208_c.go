package main

import (
	"bufio"
	"fmt"
	"os"
	"reflect"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func main() {
	buf := make([]byte, 1024*1024)
	sc.Buffer(buf, bufio.MaxScanTokenSize)
	sc.Split(bufio.ScanWords)
	defer out.Flush() // !!!!caution!!!! you must use Fprint(out, ) not Print()
	/* --- code --- */
	N, K := nextInt(), nextInt()
	a := nextInts(N)
	b := append([]int{}, a...)

	fmt.Println("a:")
	for _, v := range a {
		fmt.Println(v)
	}

	fmt.Println("b:")
	for _, v := range b {
		fmt.Println(v)
	}

	q := K / N
	m := K % N
	sort.Ints(b)
	moraenMax := b[m]
	// fmt.Fprintln(out, ans, m, a, b, moraenMax)
	for i := 0; i < N; i++ {
		if a[i] < moraenMax {
			fmt.Fprintln(out, q+1)
		} else {
			fmt.Fprintln(out, q)
		}
	}
}

// -*-*-*-*-*-*-*-*-
// * I/O utilities *
// -*-*-*-*-*-*-*-*-

func next() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	a, _ := strconv.Atoi(next())
	return a
}

func nextFloat64() float64 {
	a, _ := strconv.ParseFloat(next(), 64)
	return a
}

func nextInts(n int) []int {
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		ret[i] = nextInt()
	}
	return ret
}
func nextFloats(n int) []float64 {
	ret := make([]float64, n)
	for i := 0; i < n; i++ {
		ret[i] = nextFloat64()
	}
	return ret
}
func nextStrings(n int) []string {
	ret := make([]string, n)
	for i := 0; i < n; i++ {
		ret[i] = next()
	}
	return ret
}

func chars(s string) []string {
	ret := make([]string, len([]rune(s)))
	for i, v := range []rune(s) {
		ret[i] = string(v)
	}
	return ret
}

// PrintOut with util device
func PrintOut(src interface{}, joinner string) {
	switch reflect.TypeOf(src).Kind() {
	case reflect.Slice:
		s := reflect.ValueOf(src)
		for idx := 0; idx < s.Len(); idx++ {
			fmt.Fprintf(out, "%v", s.Index(idx))
			if idx < s.Len()-1 {
				fmt.Fprintf(out, "%s", joinner)
			} else {
				fmt.Fprintln(out)
			}
		}
	default:
		fmt.Fprintln(out, "fuck")
	}
}

// -*-*-*-*-*-*-*-
// *  Structures *
// -*-*-*-*-*-*-*-

// Queue ... only for integers
type Queue struct {
	queue []int
}

// Enqueue ... the so-called enqueue
func (q *Queue) Enqueue(x int) {
	q.queue = append(q.queue, x)
}

// Dequeue ... the so-called dequeue
func (q *Queue) Dequeue() (ret int) {
	ret, q.queue = q.queue[0], q.queue[1:]
	return
}

// Len ... return length of queue
func (q *Queue) Len() (ret int) {
	return len(q.queue)
}

// reverse any type of slice
func reverseAny(slice interface{}) {
	n := reflect.ValueOf(slice).Len()
	swap := reflect.Swapper(slice)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		swap(i, j)
	}
}

// -*-*-*-*-*-*-*-*-
// * tool snippets *
// -*-*-*-*-*-*-*-*-
func duplicate2Int(base [][]int) (ret [][]int) {
	ret = make([][]int, len(base))
	for i, v := range base {
		ret[i] = append([]int{}, v...)
	}
	return
}

func min(a, b int) int {
	x, y := toFloat64(a), toFloat64(b)
	if x < y {
		return a
	}
	return b
}

func max(a, b int) int {
	x, y := toFloat64(a), toFloat64(b)
	if x > y {
		return a
	}
	return b
}

func toFloat64(v interface{}) float64 {
	r := reflect.ValueOf(v)
	if r.IsValid() {
		switch r.Kind() {
		case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64,
			reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64,
			reflect.Float32, reflect.Float64:
			var x float64
			return r.Convert(reflect.TypeOf(x)).Interface().(float64)
		default:
			return 0

		}
	}
	return 0
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-
// * Algorithms Utility Zone *
// -*-*-*-*-*-*-*-*-*-*-*-*-*-

// -*-*-*-*-*-*-*-
// * 1. nibutan  *
// -*-*-*-*-*-*-*-
func lowerBound(arr []int, target int) int {
	l, r := 0, len(arr)
	for l < r {
		mid := (l + r) / 2
		if arr[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

func upperBound(arr []int, target int) int {
	l, r := 0, len(arr)
	for l < r {
		mid := (l + r) / 2
		if target < arr[mid] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// * math flavor typical theories *
// *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
func gcd(a, b int) int {
	if a > b {
		return gcd(b, a)
	}
	for a != 0 {
		a, b = b%a, a
	}
	return b
}

func pow(a, b int) (ret int) {
	ret = a
	// 10^2 = 100ってことは10に10を1回掛けることだね
	// なので初期値を含めると上限b-1未満
	for i := 0; i < b-1; i++ {
		ret *= a
	}
	return
}

func powMod(n, m, mod int) (ret int) {
	ret = 1
	for m > 0 {
		if m&1 == 1 {
			ret *= n
			ret %= mod
		}
		n *= n
		n %= mod
		m >>= 1
	}
	return ret
}

func ncr(n, r int) int {
	// せいぜいn<10^2くらいの精度しかなくない？
	res := 1
	for i := 1; i <= r; i++ {
		res = res * (n - i + 1) / i
	}
	return res
}

func ncrMod(n, r, mod int) int {
	// 呼び出すたびにテーブルを作るのは愚です（どうしようかね）
	_n := 1000000
	g1 := make([]int, _n+1)
	g1[0], g1[1] = 1, 1
	g2 := make([]int, _n+1)
	g2[0], g2[1] = 1, 1
	inverse := make([]int, _n+1)
	inverse[0], inverse[1] = 0, 1
	for i := 2; i <= _n; i++ {
		g1[i] = (g1[i-1] * i) % mod
		inverse[i] = mod - inverse[mod%i]*(mod/i)%mod
		g2[i] = (g2[i-1] * inverse[i]) % mod
	}

	return g1[n] * (g2[r] * g2[n-r] % mod) % mod
}

// たくさん使う場合は↑より↓のほうが1000倍くらい早い
func combMod(n, m, MOD int) int {
	return factorial(n, n-m+1, MOD) * _pow(factorial(m, 2, MOD), MOD-2, MOD) % MOD
}

func _pow(x, n, MOD int) int {
	r := 1
	for ; n > 0; n /= 2 {
		if n%2 == 1 {
			r = r * x % MOD
		}
		x = x * x % MOD
	}
	return r
}

func factorial(n, m, MOD int) int {
	r := 1
	for i := m; i <= n; i++ {
		r = r * i % MOD
	}
	return r
}

func nextPerm(arr []int) func() []int {
	/*
		how to use it:
			this is a generator, so should be invoked such as below example.

			"""code"""
			np := nextPermutation(arr)
			for{
				lis := np()
				if len(lis) == 0{
					break
				}
				fmt.Println(lis)
			}
			"""code end"""
	*/
	first := true
	ret := append([]int{}, arr...)
	_nextPerm := func() []int {
		if first {
			first = false
			return arr
		}
		n := len(ret)
		for i := n - 2; i >= 0; i-- {
			if ret[i] < ret[i+1] {
				j := n
				for {
					j--
					if ret[i] < ret[j] {
						break
					}
				}
				ret[i], ret[j] = ret[j], ret[i]
				for k := n - 1; i < k; i, k = i+1, k-1 {
					ret[i+1], ret[k] = ret[k], ret[i+1]
				}
				return ret
			}
		}
		return []int{}
	}
	return _nextPerm
}

// Enumerate all the divisors.
func enumDiv(x int) (ret []int) {
	ret = []int{}
	for i := 1; i*i <= x; i++ {
		if x%i == 0 {
			ret = append(ret, i)
			if i != 1 && i*i != x {
				ret = append(ret, x/i)
			}
		}
	}
	return
}

// 素因数分解
func primeFactorization(x int) map[int]int {
	ret := make(map[int]int)
	for i := 2; i*i <= x; i++ {
		for x%i == 0 {
			x /= i
			ret[i] += 1
		}
	}
	if x > 1 {
		ret[x] += 1
	}
	return ret
}
