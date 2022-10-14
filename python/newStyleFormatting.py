#!/usr/bin/env python3
#import pdb; pdb.set_trace()
import math
import os

# You came to work in a big company as a Senior Python Developer. Unfortunately 
# your team members seem to be quite old-school: you can see old-style string 
# formatting everywhere in the code, which is not too cool. You tried to force 
# the team members to start using the new style formatting, but it looks like 
# it will take some time to persuade them: old habits die hard, especially in 
# old-school programmers.

# To show your colleagues that the new style formatting is not that different 
# from the old style, you decided to implement a function that will turn the 
# old-style syntax into a new one. Implement a function that will turn the 
# old-style string formating s into a new one so that the following two strings 
# have the same meaning:

    # s % (*args)
    # s.format(*args)

# Example

# For s = "We expect the %f%% growth this week", the output should be
# solution(s) = "We expect the {}% growth this week".

# Input/Output

    # [execution time limit] 0.5 seconds (cpp)

    # [input] string s

    # A correct old-style formatting string. It is guaranteed that each % 
	# sign in it is always followed either by a correct conversion type or 
	# by another '%' sign (see this for reference). It is also guaranteed 
	# that it doesn't contain curly brackets ('{' or '}').

    # Guaranteed constraints:
    # 1 ≤ s.length ≤ 70.

    # [output] string

    # A new-style formatting string without positional indices.


def solution(s): 
	result = s
	return result


if __name__ == "__main__":
# program starts here, methods are defined above
	mys=["We expect the %f%% growth this week",
		"%d%d%%-growth in products is expected quite soon",
		"Much %%s we have here!",
		"Nothing to insert.",
		"New style formatting (like %s) is waay cooler than old-style (i.e. %s)",
		"%%%%x",
		"%%%%%d"]

	result=["We expect the {}% growth this week",
			"{}{}%-growth in products is expected quite soon",
			"Much %s we have here!",
			"Nothing to insert.",
			"New style formatting (like {}) is waay cooler than old-style (i.e. {})",
			"%%x",
			"%%{}"]
	
	for i in range(len(mys)):
		myresult=solution(mys[i])
		print(" string"," "*9, mys[i],"\n ***should be*** ", result[i], "\n ***and is***    ", myresult,"\n")

	

