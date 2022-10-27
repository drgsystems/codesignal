#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()
from operator import itemgetter

# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# You've been preparing all night for the upcoming test and entered 
# the class certain that you will ace it. Now that you received the 
# test questions, you died inside a little: looks like you prepared 
# for the test on a completely different topic.

# You're not even sure if you should bother to answer the questions. 
# You still have some hope though: it is known that there's a glitch 
# in the test preparing system, so that if the sum of digits of question 
# ids is divisible by k, the answer to each question has a 90% probability 
# to be an A.

# Given the list of question ids, determine if the sum of their digits 
# is divisible by k to see if it's worth trying to pass the test.

# Example

# For ids = [529665, 909767, 644200] and k = 3, the output should be
# solution(ids, k) = true.

# The sum of digits is

# (5 + 2 + 9 + 6 + 6 + 5) + (9 + 0 + 9 + 7 + 6 + 7) + (6 + 4 + 4 + 2 + 0 + 0) = 87

# which is divisible by 3. Today is your lucky day after all!

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.integer ids

    # Array of unique question ids.

    # Guaranteed constraints:
    # 1 ≤ ids.length ≤ 50,
    # 0 ≤ ids[i] ≤ 106.

    # [input] integer k

    # The number that causes a glitch in the test preparing system.

    # Guaranteed constraints:
    # 2 ≤ k ≤ 10.

    # [output] boolean

    # true if the total sum of digits in ids is divisible by k, false otherwise.



def solution(ids, k):
	digitSum = lambda number: 0 if number == 0 else (number % 10) + digitSum (number // 10)

	sm = 0
	for questionId in ids:
		sm += digitSum(questionId)
	return sm % k == 0

if __name__ == "__main__":
# program starts here, methods are defined above

	ids=[[529665, 909767, 644200],
		[505472, 823554, 608771, 106888, 819471, 116625, 689811, 309397, 942937, 902554, 677532, 562522, 145067, 508460, 3501, 293533, 898993, 407738, 156093, 847039, 668357, 645962, 297698, 58190, 781139, 64724, 169176, 239193, 416474, 694882, 974958, 766959, 97136, 788718, 641266, 200950, 468728, 245625, 324219, 311677],
		[603040, 834416, 903427, 254312, 524329, 740203, 382224, 90673, 883043, 263478, 546458, 785567],
		[298883, 498186, 352013, 193422, 581267, 466197, 221464, 994847, 278436, 954278, 625841, 418088, 499117, 764592, 802481, 161461, 872376, 220346, 861244, 308170, 250815, 750018, 985668, 223813, 601672, 584777, 28874, 226123, 642126, 611023, 222289, 287058, 806052, 405327, 71114, 755943, 813290, 943731, 911220, 432508],
		[882144, 993441, 460418, 325830, 404529, 912233, 255818, 68407, 94032, 6801, 38227, 997782, 747063, 754688, 725338, 802267, 673468, 271162, 478014, 21599],
		[0],
		[2],
		[1010, 10],
		[1234, 56],
		[1324, 56, 120]]

	myk=[3,6,7,8,6,2,2,4,7,10]
	results=[True,False,True,True,False,True,True,False,True,False]
	
	for i in range(len(ids)):
		myresult=solution(ids[i],myk[i])
		print(" test ", i, " should be ", results[i], "\n and is "," "*11, myresult,"\n")