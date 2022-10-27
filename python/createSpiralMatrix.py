#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()


# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# A spiral matrix is a square matrix of size n × n. It contains 
# all the integers in range from 1 to n * n so that number 1 is 
# written in the bottom right corner, and all other numbers are 
# written in increasing order spirally in the counterclockwise 
# direction.

# Given the size of the matrix n, your task is to create a 
# spiral matrix.

# Example

# For n = 3, the output should be

# solution(n) = [[5, 4, 3],
                         # [6, 9, 2],
                         # [7, 8, 1]]

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] integer n

    # Matrix size, a positive integer.

    # Guaranteed constraints:
    # 3 ≤ n ≤ 75.

    # [output] array.array.integer

    # A spiral matrix of size n.



def solution(n):
    dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
    curDir = 0
    curPos = (n - 1, n - 1)
    res = [[0 for x in range(n)] for y in range(n)]

    for i in range(1, n * n + 1):
        res[curPos[0]][curPos[1]] = i
        nextPos = curPos[0] + dirs[curDir][0], curPos[1] + dirs[curDir][1]
        if not (0 <= nextPos[0] < n and
                0 <= nextPos[1] < n and
                res[nextPos[0]][nextPos[1]] == 0):
            curDir = (curDir + 1) % 4
            nextPos = curPos[0] + dirs[curDir][0], curPos[1] + dirs[curDir][1]
        curPos = nextPos

    return res

if __name__ == "__main__":
# program starts here, methods are defined above

	results=[[[5,4,3], [6,9,2], [7,8,1]],
		[[7,6,5,4], [8,15,14,3], [9,16,13,2], [10,11,12,1]],
		[[9,8,7,6,5], [10,21,20,19,4], [11,22,25,18,3], [12,23,24,17,2], [13,14,15,16,1]],
		[[11,10,9,8,7,6], [12,27,26,25,24,5], [13,28,35,34,23,4], [14,29,36,33,22,3], [15,30,31,32,21,2], [16,17,18,19,20,1]],
		[[13,12,11,10,9,8,7], [14,33,32,31,30,29,6], [15,34,45,44,43,28,5], [16,35,46,49,42,27,4], [17,36,47,48,41,26,3], [18,37,38,39,40,25,2], [19,20,21,22,23,24,1]],
		[[15,14,13,12,11,10,9,8], [16,39,38,37,36,35,34,7], [17,40,55,54,53,52,33,6], [18,41,56,63,62,51,32,5], [19,42,57,64,61,50,31,4], [20,43,58,59,60,49,30,3], [21,44,45,46,47,48,29,2], [22,23,24,25,26,27,28,1]]]

	myk=[3,4,5,6,7,8]
	
	for i in range(len(myk)):
		myresult=solution(myk[i])
		print(" test ", i, " should be ", results[i], "\n and is "," "*11, myresult,"\n")