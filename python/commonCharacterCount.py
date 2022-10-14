#!/usr/bin/env python3
# import pdb; pbd.set_trace()

# Given two strings, find the number of common characters between them.

# Example

# For s1 = "aabcc" and s2 = "adcaa", the output should be
# solution(s1, s2) = 3.

# Strings have 3 common characters - 2 "a"s and 1 "c".

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] string s1

    # A string consisting of lowercase English letters.

    # Guaranteed constraints:
    # 1 ≤ s1.length < 15.

    # [input] string s2

    # A string consisting of lowercase English letters.

    # Guaranteed constraints:
    # 1 ≤ s2.length < 15.

    # [output] integer
	
#import difflib
s1="aabcc"
s2="adcaa"
s3="abca"
s4="xyzbac"
s5="zzzz"
s6="zzzzzzz"

# def solution(s1, s2):
	# del_count=0
	# add_count=0
	# s1_len=len(s1)
	# s2_len=len(s2)
	# char_test=""

	# for i,s in enumerate(difflib.ndiff(s1, s2)):
		# if s[0]==' ': continue
		# elif s[0]=='-':
			# print(u'Delete "{}" from position {}'.format(s[-1],i))
			# del_count+=1
		# elif s[0]=='+':
			# print(u'Add "{}" to position {}'.format(s[-1],i))
			# add_count+=1
def solution(s1,s2):
	total=0
	i=0
	for i in range(len(s1)):
		count=s2.find(s1[i])
		print("s1[",i,"]=",s1[i],"found ",count," in ",s2)
		if( count >=0):
			total+=1
			s2=s2.replace(s2[count],'',1)
	print("total=",total)
	return total
	

print("correct number of common characters is 3, s1=",s1," and s2=",s2," common characters found= ",solution(s1,s2))
print("correct number of common characters is 3, s3=",s3," and s4=",s4," common characters found= ",solution(s3,s4))
print("correct number of common characters is 4, s5=",s5," and s6=",s6," common characters found= ",solution(s5,s6))	