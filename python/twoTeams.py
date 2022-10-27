#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()
import math
import os
# import awkward as ak
# import numpy as np

# Implement the missing code, denoted by ellipses. You may not modify 
# the pre-existing code.

# There are some students standing in a row, each has some number written 
# on their back. The students are about to divide into two teams by counting 
# off by twos: those standing at the even positions (0-based) will go to 
# team A, and those standing at the odd position will join the team B.

# Your task is to calculate the difference between the sums of numbers 
# written on the backs of the students that will join team A, and those 
# written on the backs of the students that will join team B.

# Example

# For students = [1, 11, 13, 6, 14], the output should be
# solution(students) = 11.

# Students with numbers 1, 13 and 14 will join team A, and students with 
# numbers 11 and 6 will join team B. Thus, the answer is (1 + 13 + 14) - (11 + 6) = 11.

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.integer students

    # Array of numbers written on the students' backs.

    # Guaranteed constraints:
    # 2 ≤ students.length ≤ 50,
    # 1 ≤ students[i] ≤ 99.

    # [output] integer
#
# elegant way to iterate through a list for even and odd numbers
#
def solution(students):
	return(sum(students[::2])-sum(students[1::2]))

	
if __name__ == "__main__":
# program starts here, methods are defined above
	mys=[[1, 11, 13, 6, 14],
		[3, 4],
		[16, 14, 79, 8, 71, 72, 71, 10, 80, 76, 83, 70, 57, 29, 31],
		[23, 72, 54, 4, 88, 91, 8, 44],
		[23, 74, 57, 33, 61, 99, 19, 12, 19, 38, 77, 70, 20]]


	result=[11,-1,209,-38,-50]

	
	for i in range(len(mys)):
		myresult=solution(mys[i])
		print(" list ", i,"\n even - odd should be ", result[i], "\n and is ", myresult,"\n")