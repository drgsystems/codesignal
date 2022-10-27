#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()

# Implement the missing code, denoted by ellipses. You may not modify 
# the pre-existing code.

# A new scoring system was introduced in your university: from now on, 
# each test will consist of the predefined list of questions, and for 
# the ith (1-based) question a student either gets i points, or loses 
# p points as a penalty.

# Your task is to calculate the number of points a student got for some 
# test. Implement a function that would calculate the number of points 
# received for the test based on the given list of answers.

# Example

# For answers = [True, True, False, True] and p = 2, the output should be
# solution(answers, p) = 5.

# Here's why: 1 + 2 - 2 + 4 = 5.

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.boolean answers

    # Array of student's answers. answers[i] is True if the student answered 
	# the (i + 1)th question correctly, and False otherwise.

    # Guaranteed constraints:
    # 1 ≤ answers.length ≤ 20.

    # [input] integer p

    # The number of points subtracted from the final score for each incorrect result.

    # Guaranteed constraints:
    # 0 ≤ p ≤ 10.

    # [output] integer

    # The number of points the student received for the test.

def solution(answers, p):
#
#	this is the solution to the lambda test
#	I noticed it must be close to the call to the 
#	solution function.
#
    questionPoints = lambda i,ans: i + 1 if ans else -p

    res = 0
    for i, ans in enumerate(answers):
        res += questionPoints(i, ans)
    return res

if __name__ == "__main__":
# program starts here, methods are defined above
	ch=[[True, True, False, True],
		[True, False, True, False],
		[True, False],
		[True, True, True, False, True, True, True, False, True, True, True, True, False],
		[False, True, True, True, False, True],
		[False]]

	result=[5,-10,1,60,13,-10]

	p=[2,7,0,2,1,10]

	
	for i in range(len(ch)):
		myresult=solution(ch[i],p[i])
		print(" test ", i, " should be ", result[i], "\n and is "," "*11, myresult,"\n")