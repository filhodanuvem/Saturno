package main

import (
	"fmt"
)

func main() {
	number := 5
	result, err := fatorial(number)
	if err != nil {
		fmt.Println(err)
	}
	result_rec, err := fatorial_rec(number)
	if err != nil {
		fmt.Println(err)
	}

	fmt.Printf("Fatorial of %d is %d\n", number, result)
	fmt.Printf("Fatorial rec of %d is %d\n", number, result_rec)
}
