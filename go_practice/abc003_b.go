package main

import (
	"bufio"
	"fmt"
	"os"
)

var sc = bufio.NewScanner(os.Stdin)

func main() {
	var s, t string

	if sc.Scan() {
		s = sc.Text()
	}
	if sc.Scan() {
		t = sc.Text()
	}

	lose := false
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			if s[i] == '@' && !contains("atcoder@", int(t[i])) {
				lose = true
				break
			}
			if t[i] == '@' && !contains("atcoder@", int(s[i])) {
				lose = true
				break
			}
			if s[i] != '@' && t[i] != '@' {
				lose = true
				break
			}
		}
	}
	if !lose {
		fmt.Println("You can win")
	} else {
		fmt.Println("You will lose")
	}
}

func contains(s string, c int) bool {
	//fmt.Println(c)
	for _, sc := range s {
		if int(sc) == c {
			return true
		}
	}
	return false
}
