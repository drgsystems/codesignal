#!/usr/bin/env python3
import math
#import pdb; pdb.set_trace()


# Given a string consisting of lowercase English letters, find the largest 
# square number which can be obtained by reordering the string's characters 
# and replacing them with any digits you need (leading zeros are not allowed) 
# where same characters always map to the same digits and different characters 
# always map to different digits.

# If there is no solution, return -1.

# Example

    # For s = "ab", the output should be
    # solution(s) = 81.
    # The largest 2-digit square number with different digits is 81.
    # For s = "zzz", the output should be
    # solution(s) = -1.
    # There are no 3-digit square numbers with identical digits.
    # For s = "aba", the output should be
    # solution(s) = 900.
    # It can be obtained after reordering the initial string into "baa" and 
	# replacing "a" with 0 and "b" with 9.

# Input/Output

    # [execution time limit] 0.5 seconds (cpp)

    # [input] string s

    # Guaranteed constraints:
    # 1 ≤ s.length < 10.

    # [output] integer


def solution(s):
    counted = []
    num = []
    for i in range(0,len(s)):
        print("i=",i," s[i]=",s[i])
        if s[i] not in counted:
            num.append(s.count(s[i]))
            counted.append(s[i])
    digits = sum(num)
    num = sorted(num)
    print("\ndigits=", digits, " num=", num)
  
    x = 1
    #while(x!=3):
    for j in range(int(math.ceil(pow(pow(10,digits),.5))),0,-1):
        #j= int(math.ceil(pow(pow(10,digits),.5)))
        x += 1
        sq = str(int(pow(j,2)))
        print("digits=",digits," j=",j," sq=",sq, " pow(10,digits)=", pow(10,digits), "pow(pow(10,digits),.5)=",pow(pow(10,digits),.5))			
        counted = []
        numSq = []
        for i in range(0,len(sq)):
            if sq[i] not in counted:
                numSq.append(sq.count(sq[i]))
                counted.append(sq[i])
        numSq = sorted(numSq)
        print("numSq=",numSq," counted=",counted, " sq=",sq,"\n")		
        if num == numSq:
            return int(sq)
    
    return -1


if __name__ == "__main__":
# program starts here, methods are defined above

    print("string ab should return 81 and result is ",solution("ab"))
	# print("string zzz should return -1 and result is ",solution("zzz"))
    print("string aba should return 900 and result is ",solution("aba"))
    #print("string abcbbb should return 810000 and result is ",solution("abcbbb"))	
    print("string abc should return 961 and result is ",solution("abc"))
	# print("string aaaabbcde should return 999950884 and result is ",solution("aaaabbcde"),"\n")

