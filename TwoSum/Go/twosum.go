/*
	TwoSum takes a target sum and any number of NON-REPEATING integers and returns
	the two integers that add up to the target if they exist.
	For example, with a target of 5, and the list of integers 1 2 3 4
	the algorithm would return [2,3]
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Printf("Input Target Sum: ")
	var target int
	fmt.Scan(&target)
	fmt.Printf("Input Array of Integers: ")
	var values []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	values = numbers(scanner.Text())

	fmt.Println(twoSum(values, target))
}

func twoSum(nums []int, target int) []int {
	// key is complement, value is index
	comps := make(map[int]int, len(nums))
	for i, val := range nums {
		if index, ok := comps[val]; ok {
			return []int{nums[index], nums[i]}
		}
		comps[target-val] = i
	}
	return []int{}
}

func numbers(s string) []int {
	var n []int
	for _, f := range strings.Fields(s) {
		i, err := strconv.Atoi(f)
		if err == nil {
			n = append(n, i)
		}
	}
	return n
}
