#!/usr/bin/env python3
#import pdb; pdb.set_trace()

# Some people are standing in a row in a park. 
# There are trees between them which cannot be moved. 
# Your task is to rearrange the people by their 
# heights in a non-descending order without moving 
# the trees. People can be very tall!

# Example

# For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
# solution(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.integer a

    # If a[i] = -1, then the ith position is occupied by a tree. 
	# Otherwise a[i] is the height of a person standing in the ith position.

    # Guaranteed constraints:
    # 1 ≤ a.length ≤ 1000
    # -1 ≤ a[i] ≤ 1000.

    # [output] array.integer

    # Sorted array a with all the trees untouched.
# s1.append(x)
# s1.insert(index,value)
# s1.extend(s2)
#
a = [-1, 150, 190, 170, -1, -1, 160, 180]

def solution(a):
	b=[]
	for index, value in enumerate(a):
		if(value != -1):
			b.append(value)
	b.sort()
	b_index=0
	for index, value in enumerate(a):
		if(value != -1):
			a[index]=b[b_index]
			b_index+=1
	return a

print("original array a =",a)
print(" array a =",solution(a))