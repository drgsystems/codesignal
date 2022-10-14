#!/usr/bin/env python3


def solution(inputString):
	char =list(inputString)
	open_bracket = []
	for i,c in enumerate(char):
		if c == '(':
			open_bracket.append(i)
		elif c == ')':
			j = open_bracket.pop()
			char[j:i] = char[i:j:-1]
	return ''.join(c for c in char if c not in '()')



if __name__ == "__main__":
	print("original is foo(bar(baz))blim, solution is ",solution("foo(bar(baz))blim"))
	#print(solution("foo(bar(baz))blim"))
