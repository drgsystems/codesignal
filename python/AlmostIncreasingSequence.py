#!/usr/bin/env python3
#import pdb; pdb.set_trace()

# Given a sequence of integers as an array, determine whether it is 
# possible to obtain a strictly increasing sequence by removing no 
# more than one element from the array.
# 
# Note: sequence a0, a1, ..., an is considered to be a strictly 
# increasing if a0 < a1 < ... < an. Sequence containing only one 
# element is also considered to be strictly increasing.
# 
# Example
#
#     For sequence = [1, 3, 2, 1], the output should be
#     solution(sequence) = false.
#
#     There is no one element in this array that can be removed in order to get a strictly increasing sequence.
#
#     For sequence = [1, 3, 2], the output should be
#     solution(sequence) = true.
#
#     You can remove 3 from the array to get the strictly increasing sequence [1, 2]. 
# 	  Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].
#
#Input/Output
#
#    [execution time limit] 4 seconds (py3)
#
#    [input] array.integer sequence
#
#    Guaranteed constraints:
#    2 ≤ sequence.length ≤ 1,000,000,
#    -1,000,000 ≤ sequence[i] ≤ 1,000,000.
#
#    [output] boolean
#
#    Return true if it is possible to remove one element from the array in order to get a strictly increasing sequence, otherwise return false.

def solution(sequence):
	#sequence.sort()
	array_size=len(sequence)-1
	loop_count=0
	error_count=0
#	print("sequence=",sequence," loop_count=",loop_count," error_count=",error_count," array_size=",array_size)
	while loop_count < array_size :
		if(sequence[loop_count+1]<=sequence[loop_count]): #or sequence[loop_count+1]>=sequence[loop_count+2]):
			if(loop_count==0 or (loop_count!=0 and sequence[loop_count+1]>sequence[loop_count-1])):
				del sequence[loop_count]
			else:
				del sequence[loop_count+1]
			error_count+=1		
			array_size=len(sequence)-1
#			print("sequence=",sequence," loop_count=",loop_count," error_count=",error_count," array_size=",array_size)
			loop_count=0
			if(error_count >1):
				return False
		else:
			loop_count+=1
	return True

mylist = [
	[1,2,1,2],"false",
	[1,3,2,1],"false",
	[1, 1, 2, 3, 4, 4],"false",
	[10, 1, 2, 3, 4, 5],"true",
	[1, 1, 2, 3, 4, 4],"false",
	[1, 2, 3, 4, 3, 6],"true",
	[3, 5, 67, 98, 3],"true",
	[1, 2, 3, 4, 5, 3, 5, 6],"false",
	[40, 50, 60, 10, 20, 30],"false",
	[1, 2, 3, 4, 99, 5, 6],"true",
	[1, 2, 5, 3, 5],"true"
	]

count=len(mylist)//2
print("mylist contains ",count, "elements")	

for i in range(count):
	print("array#",i," to test=",mylist[i*2])
	print("result",i," should be ",mylist[i*2+1]," and is ",solution(mylist[i*2])," array after test=",mylist[i*2],"\n")