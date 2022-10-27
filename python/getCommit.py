#!/usr/bin/env python3
import pdb; 
#pdb.set_trace()
import math
import os

# Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.

# The Abanamama Version System (AVS) is a software versioning and revision control system 
# used in highly secure environments. In this system, each commit is assigned a unique name, 
# the first part of which consists of the username encrypted in the base-4 system using 
# symbols '0', '?', '+', and '!', and the second part consists of symbols of English alphabet.

# Given such commit, your task is go remove the username part from it and return the second 
# part as an answer.

# Example

# For commit = "0??+0+!!someCommIdhsSt", the output should be
# solution(commit) = "someCommIdhsSt".

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] string commit

    # Commit in the format given above. Note, that it is possible that it doesn't contain 
	# the first or the second part.

    # Guaranteed constraints:
    # 5 ≤ commit.length ≤ 45.

    # [output] string

    # The second part of the commit.

def solution(commit):
    return ''.join([ x for x in commit if x.isalpha() ])

if __name__ == "__main__":
# program starts here, methods are defined above
	mys=["0??+0+!!someCommIdhsSt",
		"noAUTHORofTHIScOmMiT",
		"?????!+0",
		"!0?!++?empThddsEldfeojLEJlfdk",
		"+?!00+?sdfejdcdfjwlejflsfjDjfejfLDJfodKJDFLJq"]

	result=["someCommIdhsSt",
			"noAUTHORofTHIScOmMiT",
			"",
			"empThddsEldfeojLEJlfdk",
			"sdfejdcdfjwlejflsfjDjfejfLDJfodKJDFLJq"]
	
	for i in range(len(mys)):
		myresult=solution(mys[i])
		print(" string"," "*9, i,"\n ***should be*** ", result[i], "\n ***and is***    ", myresult,"\n")