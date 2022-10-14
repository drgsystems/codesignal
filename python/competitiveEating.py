#!/usr/bin/env python3
#import pdb; pdb.set_trace()
import math
import os

# Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.

# The World Wide Competitive Eating tournament is going to be held in your town, and you're 
# the one who is responsible for keeping track of time. For the great finale, a large billboard 
# of the given width will be installed on the main square, where the time of possibly new world 
# record will be shown.

# The track of time will be kept by a float number. It will be displayed on the board with the 
# set precision precision with center alignment, and it is guaranteed that it will fit in the 
# screen. Your task is to test the billboard. Given the time t, the width of the screen and the 
# precision with which the time should be displayed, return a string that should be shown on the 
# billboard.

# Example

# For t = 3.1415, width = 10, and precision = 2,
# the output should be

# solution(t, width, precision) = "   3.14   "

# Input/Output

    # [execution time limit] 4 seconds (py)

    # [input] float t

    # The time to be displayed on the billboard. It is guaranteed that t has at most 5 digits after 
	# the decimal point.

    # Guaranteed constraints:
    # 0 ≤ t < 1000.

    # [input] integer width

    # The width of the billboard. It is guaranteed that it's big enough to display the time t with the 
	# desired precision.

    # In case it's impossible to align the time perfectly in the center, left padding should be 1 
	# whitespace character shorter than right padding.

    # Guaranteed constraints:
    # 3 ≤ width ≤ 20.

    # [input] integer precision

    # Precision with which the number should be displayed.

    # Guaranteed constraints:
    # 0 ≤ precision ≤ 10.

    # [output] string

    # A string of length width representing the time t as it will be displayed on the billboard.

def solution(t, width, precision):
    #return "{0:^{1}.{2}f}".format(t,width,precision)  this got 14 of 14 correct after removing , after {1}
	return  '{:^{}.{}f}'.format(t,width,precision)  # this gets 14 of 14 correct - 
	#https://www.google.com/search?client=firefox-b-1-d&q=Competitive+Eating+codesignal#fpstate=ive&vld=cid:ff589b28,vid:zy8e57rpyzU,st:0

if __name__ == "__main__":
# program starts here, methods are defined above
	myt=[3.1415,29.8245,9.34,837.28472,0.01]
	width=[10,4,10,20,3]
	precision=[2,0,2,7,0]
	result=["   3.14   ","    30    ","9.34","    837.2847200     ","   x   "]
	
	for i in range(len(myt)):
		myresult=solution(myt[i],width[i],precision[i])
		print("time=",myt[i]," width=",width[i]," precision=",precision[i]," should be ",result[i], " results=", myresult)

	

