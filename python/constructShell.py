#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()


# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# A 2D list lst of size 2 * n - 1 is called a shell if it is 
# filled with zeros and has the following configuration:

    # lst[0] contains one element;
    # lst[1] contains two elements;
    # ...
    # lst[n - 2] contains n - 1 elements;
    # lst[n - 1] contains n elements;
    # lst[n] contains n - 1 elements;
    # ...
    # lst[2 * n - 3] contains two elements;
    # lst[2 * n - 2] contains one element.

# Given an integer n, return a shell list.

# Example

# For n = 3, the output should be

# solution(n) = [[0],
                     # [0, 0],
                     # [0, 0, 0],
                     # [0, 0],
                     # [0]]

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] integer n

    # An integer defining the size of the shell.

    # Guaranteed constraints:
    # 1 ≤ n ≤ 30.

    # [output] array.array.integer

    # A shell.




def solution(n):
    return [[0]*min(x,2*n-x) for x in range(1,2*n)]



if __name__ == "__main__":
# program starts here, methods are defined above

	results=[[[0], 
			 [0,0], 
			 [0,0,0], 
			 [0,0], 
			 [0]],
			[[0], 
			 [0,0], 
			 [0,0,0], 
			 [0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0], 
			 [0,0,0], 
			 [0,0], 
			 [0]],
			[[0], 
			 [0,0], 
			 [0,0,0], 
			 [0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0], 
			 [0,0,0], 
			 [0,0], 
			 [0]],
			[[0], 
			 [0,0], 
			 [0,0,0], 
			 [0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0], 
			 [0,0,0], 
			 [0,0], 
			 [0]],
			[[0], 
			 [0,0], 
			 [0,0,0], 
			 [0,0,0,0], 
			 [0,0,0,0,0], 
			 [0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0,0,0,0], 
			 [0,0,0,0,0,0,0,0,0,0,0,0],
			 [0,0,0,0,0,0,0,0,0,0,0],
			 [0,0,0,0,0,0,0,0,0,0],
			 [0,0,0,0,0,0,0,0,0],
			 [0,0,0,0,0,0,0,0],
			 [0,0,0,0,0,0,0],
			 [0,0,0,0,0,0],
			 [0,0,0,0,0],
			 [0,0,0,0],
			 [0,0,0],
			 [0,0],
			 [0]],
			[[0]]]

	n=[3,5,10,8,13,1]
	
	for i in range(len(n)):
		myresult=solution(n[i])
		print(" test ", i, " should be ", results[i], "\n and is "," "*11, myresult,"\n")