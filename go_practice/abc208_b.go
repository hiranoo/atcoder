package main

// func main() {
// 	br := bufio.NewReader(os.Stdin)
// 	var p int
// 	fmt.Fscan(br, &p)

// 	coins := make([]int, 11)
// 	coins[0] = 1
// 	for i := 0; i < 10; i++ {
// 		coins[i+1] = (i + 1) * coins[i]
// 	}

// 	ans := 0
// 	for i := 10; i > 0; i-- {
// 		if p >= coins[i]*100 {
// 			ans += 100
// 			p -= coins[i] * 100
// 		} else {
// 			ans += p / coins[i]
// 			p %= coins[i]
// 		}
// 		if p == 0 {
// 			fmt.Println(ans)
// 			return
// 		}
// 	}
// }
