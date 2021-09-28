// package main

// import (
// 	"bufio"
// 	"fmt"
// 	"os"
// )

// func main() {
// 	br := bufio.NewReader(os.Stdin)
// 	var n, a, b int
// 	fmt.Fscan(br, &n, &a, &b)

// 	ans := 0
// 	for i := 1; i <= n; i++ {
// 		digit_sum := 0
// 		for j := 1; j <= 10000; j *= 10 {
// 			digit_sum += (i / j) % 10
// 		}
// 		if a <= digit_sum && digit_sum <= b {
// 			ans += i
// 		}
// 	}

// 	fmt.Println(ans)
// }
