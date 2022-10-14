#!/usr/bin/env python3
#import pdb; pdb.set_trace()

# Given an array of strings, return another array containing all of its longest strings.
# Example
# For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
# solution(inputArray) = ["aba", "vcd", "aba"].

# Input/Output
    # [execution time limit] 4 seconds (py3)
    # [input] array.string inputArray
    # A non-empty array.

    # Guaranteed constraints:
    # 1 ≤ inputArray.length ≤ 10,
    # 1 ≤ inputArray[i].length ≤ 10.

    # [output] array.string
    # Array of the longest strings, stored in the same order as in the inputArray.

# Test 1
# Input:

# inputArray:
 # ["aba", 
 # "aa", 
 # "ad", 
 # "vcd", 
 # "aba"]

# Expected Output:
 # ["aba", 
 # "vcd", 
 # "aba"]


def solution(inputArray):
	output=[]
	array_size=len(inputArray)
	max_len=len(max(inputArray, key=len))
#	print("max_len=",max_len)
	j = 0
	for j in range(array_size):
		if(len(inputArray[j])==max_len):
			output.append(inputArray[j])
#			print("output=",output)
	return output

inputArray1=[
	"aba", 
	"aa", 
	"ad", 
	"vcd", 
	"aba"
	]


	
print("inputArray1=",inputArray1," output=",solution(inputArray1))
	