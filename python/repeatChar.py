#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()

# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# To make debug output more understandable, you often separate 
# sets of logs by a single line of the same character. Since 
# you use this method very often, you'd like to write a function 
# that would handle printing the separator.

# Implement a function that, given a character ch and the number 
# of times it should be repeated n, returns a string of n characters ch.

# Example

# For ch = '*' and n = 20, the output should be
# solution(ch, n) = "********************".

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] char ch

    # The character that should be repeated.

    # [input] integer n

    # The number of times the given character should be repeated.

    # Guaranteed constraints:
    # 1 ≤ n ≤ 100.

    # [output] string

    # A string consisting of n characters ch


if __name__ == "__main__":
# program starts here, methods are defined above
	ch=["*",
		"!",
		"#",
		"?",
		"@"]

	result=["********************", 
			"!!!!!!!!!!", 
			"###########", 
			"????????????????????",
			"@@@@@@@@@@@@"]

	n=[20,10,11,20,12]
#
#	this is the solution to the lambda test
#	I noticed it must be close to the call to the 
#	solution function.
#
	solution = lambda ch,n: ch*n
	
	for i in range(len(ch)):
		myresult=solution(ch[i],n[i])
		print(" test ", i, " should be ", result[i], "\n and is "," "*11, myresult,"\n")