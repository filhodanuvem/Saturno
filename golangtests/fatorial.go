package main

import (
	"errors"
)

func fatorial(number int) (result int, err error) {
	result = 1
	if number < 0 {
		return 0, errors.New("Number may be higher zero")
	}
	for number > 1 {
		result *= number
		number--
	}

	return
}

func fatorial_rec(number int) (result int, err error) {
	result = 1
	if number < 0 {
		return 0, errors.New("Number may be higher zero")
	}

	if number <= 1 {
		return 1, nil
	}

	var result_inter int
	result_inter, err = fatorial_rec(number - 1)
	if err != nil {
		return 0, err
	}

	result *= number * result_inter

	return result, nil
}
