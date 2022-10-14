#!/usr/bin/env python3
#import pdb; pdb.set_trace()

# Ticket numbers usually consist of an even number of digits. 
# A ticket number is considered lucky if the sum of the first 
# half of the digits is equal to the sum of the second half.

# Given a ticket number n, determine if it's lucky or not.

# Example

    # For n = 1230, the output should be
    # solution(n) = true;
    # For n = 239017, the output should be
    # solution(n) = false.

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] integer n

    # A ticket number represented as a positive integer with an even number of digits.

    # Guaranteed constraints:
    # 10 ≤ n < 106.

    # [output] boolean

    # true if n is a lucky ticket number, false otherwise.

ticket1=1230 # true
ticket2=239017 # false
ticket3=23459876
ticket4=1234554321 #true

def solution(n):
	#convert number to string
	num=str(n)
	#get string length
	length=len(str(n))
	#instantiate counters
	first=0
	second=0
	#index through number
	for index, item in enumerate(num):
		if(index < length//2):
			first+=int(item)
		else:
			second+=int(item)
	print("first half = ",first," second half = ",second)
	if(first==second):
		return True
	else:
		return False

print("ticket1=",ticket1,"=",solution(ticket1))
print("ticket2=",ticket2,"=",solution(ticket2))
print("ticket2=",ticket3,"=",solution(ticket3))
print("ticket4=",ticket4,"=",solution(ticket4))