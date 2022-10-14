#!/usr/bin/env python3
# This program makes an array consecutive.

# Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, 
# each statue having an non-negative integer size. Since he likes to make things perfect, 
# he wants to arrange them from smallest to largest so that each statue will be bigger 
# than the previous one exactly by 1. 

# He may need some additional statues to be able to accomplish that. 
# Help him figure out the minimum number of additional statues needed.

# Example

# For statues = [6, 2, 3, 8], the output should be
# solution(statues) = 3.

# Ratiorg needs statues of sizes 4, 5 and 7.

# Input/Output

#    [execution time limit] 4 seconds (py3)

#     [input] array.integer statues

#     An array of distinct non-negative integers.

#    Guaranteed constraints:
#     1 ≤ statues.length ≤ 10,
#     0 ≤ statues[i] ≤ 20.

#     [output] integer

#     The minimal number of statues that need to be added to existing statues such that 
# 	it contains every integer size from an interval [L, R] (for some L, R) and no other sizes.




def solution(statues):
	statues.sort()
	myindex=0
	num_needed=0
	print("statues sorted=",statues)
	for i in range(0,len(statues)-1):
		delta=statues[myindex+1]-statues[myindex]
		print("myindex=",myindex," delta=",delta)
		if(delta > 1):
			num_needed+=delta-1
			for j in range(delta-1) :
				statues.insert(myindex+j+1,statues[myindex]+j+1)
				print("myindex+j=",myindex+j," statues=",statues)
		myindex=myindex+delta
	return num_needed

statues=[6,2,3,8]
print("array not consecutive=",statues)
num_needed=solution(statues)
print("num_needed=", num_needed," array consecutive=",statues)			
