#!/usr/bin/env python3
import pdb; 
pdb.set_trace()


# Implement the missing code, denoted by ellipses. You may 
# not modify the pre-existing code.

# You've heard somewhere that a word is more powerful than an 
# action. You decided to put this statement at a test by assigning 
# a power value to each action and each word. To begin somewhere, 
# you defined a power of a word as the sum of powers of its 
# characters, where power of a character is equal to its 1-based 
# index in the plaintext alphabet.

# Given a word, calculate its power.

# Example

# For word = "hello", the output should be
# solution(word) = 52.

# Letters 'h', 'e', 'l' and 'o' have powers 8, 5, 12 and 15, 
# respectively. Thus, the total power of the word is 8 + 5 + 12 + 12 + 15 = 52.

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] string word

    # A string consisting of lowercase English letters.

    # Guaranteed constraints:
    # 1 ≤ word.length ≤ 25.

    # [output] integer

    # Power of the given word.





def solution(word):
	# take each string element and get its integer value relative to 'a' and put in a dict so each
	# letter of the word can be accessed with its decimal value. example num['h']=8
	# (pdb) pp(locals())
	# {'num': {
    num = {w: ord(w)-96 for w in word}
    return sum([num[ch] for ch in word])



if __name__ == "__main__":
# program starts here, methods are defined above

	word=["hello","codesignal","dog","i","abdefghijklmnopqrstuvwxyz"]

	result=[52,89,26,9,348]
	
	for i in range(len(result)):
		myresult=solution(word[i])
		print(" test ", i, " should be ", result[i], "\n and is "," "*11, myresult,"\n")