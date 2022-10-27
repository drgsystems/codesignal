#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()

# Implement the missing code, denoted by ellipses. You may not 
# modify the pre-existing code.

# You were supposed to prepare a presentation about lists in Python, 
# but totally forgot about it. Now that you don't have enough time 
# for it, you decide to show some usage examples instead and say 
# with the poker face that this is how you understood the assignment.

# Now you need to implement a function that will display a list in 
# the console. Implement a function that, given a list lst, will 
# eturn it as a string as follows: "This is your list: lst".

# Example

# For lst = [1, 2, 3, 4, 5], the output should be
# solution(lst) = "This is your list: [1, 2, 3, 4, 5]".

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.integer lst

    # A list containing integer values.

    # Guaranteed constraints:
    # 0 ≤ lst.length ≤ 50,
    # -100 ≤ lst[i] ≤ 100.

    # [output] string

    # A string containing information about lst.


def solution(lst):
    return "This is your list: " + str(lst)


if __name__ == "__main__":
# program starts here, methods are defined above
	toDo=[[1, 2, 3, 4, 5],
		[],
		[-74, -71, -7, -88, 13, -22, 7, 7, 71, 28, -78, -17, 77, 10],
		[71],
		[58, -93, 20, 3, 37, 29, 94, 60, -55, 19, -57, -24, -89, -21]]

	result=["This is your list: [1, 2, 3, 4, 5]", 
			"This is your list: []", 
			"This is your list: [-74, -71, -7, -88, 13, -22, 7, 7, 71, 28, -78, -17, 77, 10]", 
			"This is your list: [71]",
			"This is your list: [58, -93, 20, 3, 37, 29, 94, 60, -55, 19, -57, -24, -89, -21]"]

	
	for i in range(len(toDo)):
		myresult=solution(toDo[i])
		print(" test ", i, " should be ", result[i], "\n and is ", myresult,"\n")