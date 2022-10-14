#!/usr/bin/env python3
#import pdb; pdb.set_trace()
import math
import re

# You found an awesome customizable Python IDE that has almost everything you'd 
# like to see in your working environment. However, after a couple days of coding 
# you discover that there is one important feature that this IDE lacks: it cannot 
# convert tabs to spaces. Luckily, the IDE is easily customizable, so you decide 
# to write a plugin that would convert all tabs in the code into the given number 
# of whitespace characters.

# Implement a function that, given a piece of code and a positive integer x will 
# turn each tabulation character in code into x whitespace characters.

# Example

# For code = "\treturn False" and x = 4, the output should be

# solution(code, x) = "    return False"

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] string code

    # Your piece of code.

    # Guaranteed constraints:
    # 0 ≤ code.length ≤ 1500.

    # [input] integer x

    # The number of whitespace characters (' ') that should replace each 
	# occurrence of the tabulation character ('\t').

    # Guaranteed constraints:
    # 1 ≤ x ≤ 16.

    # [output] string

    # The given code with tabulation characters expanded according to x.

def solution(code, x):
    return code.replace("\t", " "*x)

if __name__ == "__main__":
# program starts here, methods are defined above

	print("given string- \treturn False -, with x=4 returns ", solution("\treturn False",4))
	