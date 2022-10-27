#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()

# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# Today is a good day: it's the kth year since you started to 
# work at the company, which means you have to have a party 
# today. In order to get home earlier and prepare for the jamboree, 
# you need to get home early. You decided to remove each kth 
# tasks from your toDo list, since today is your day and you 
# can do whatever you please.

# Given the list of task ids in your toDo list, remove each kth 
# task from it and return the list of remaining tasks.

# Example

# For k = 3 and toDo = [1237, 2847, 27485, 2947, 1, 247, 374827, 22],
# the output should be
# solution(k, toDo) = [1237, 2847, 2947, 1, 374827, 22].

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] integer k

    # Guaranteed constraints:
    # 1 ≤ k ≤ 30.

    # [input] array.integer toDo

    # Ids of the tasks in your to-do list.

    # Guaranteed constraints:
    # 1 ≤ toDo.length ≤ 100,
    # 1 ≤ toDo[i] ≤ 4 · 105.

    # [output] array.integer

# start at k-1 and increment k times and delete
def solution(k, toDo):
    del toDo[k-1::k]
    return toDo

if __name__ == "__main__":
# program starts here, methods are defined above
	toDo=[[1237, 2847, 27485, 2947, 1, 247, 374827, 22],
		[1237, 2847, 27485, 2947, 1, 247, 374827, 22],
		[1237],
		[552, 987, 422, 309, 222, 949, 448, 524, 542, 562, 105, 210, 887, 762, 750, 239, 738, 920, 764],
		[82614, 34200, 25887, 53226, 32161, 9495, 49341, 81259, 83693, 30921, 46944, 8450, 63590, 97745]]

	result=[[1237, 2847, 2947, 1, 374827, 22], 
			[], 
			[1237], 
			[552, 987, 309, 222, 448, 524, 562, 105, 887, 762, 239, 738, 764],
			[82614, 25887, 32161, 49341, 83693, 46944, 63590]]
	
	k=[3,1,10,3,2]

	
	for i in range(len(toDo)):
		myresult=solution(k[i],toDo[i])
		print(" list ", i,"\n for k=", k[i], " should be ", result[i], "\n and is ", myresult,"\n")