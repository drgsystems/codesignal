#!/usr/bin/python
# this program calculates the area of a polygon

# Below we will define an n-interesting polygon. Your task is to 
# find the area of a polygon for a given n.

# A 1-interesting polygon is just a square with a side of length 1. 
# An n-interesting polygon is obtained by taking the n - 1-interesting polygon 
# and appending 1-interesting polygons to its rim, side by side. 
# You can see the 1-, 2-, 3- and 4-interesting polygons in the picture below.

# Example

#     For n = 2, the output should be
#     solution(n) = 5;
#     For n = 3, the output should be
#     solution(n) = 13.


def solution(n):
	if(n > 0) :
		mycoff=1+((n-4)*.5)
		result=((((n-1)*4)*mycoff)+(((n-1)*4)+1))
		return result
	else : return 0

n=int(1)
while n != 0 :
	n = int(input("enter a polygon number or zero to exit: "))
	x = int(solution(n))
	print("\n Area of an interesting polygon(",n,")=",x,"\n")
