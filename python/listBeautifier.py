#!/usr/bin/env python3

import math

# Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.

# Let's call a list beautiful if its first element is equal to its last element, or if a list 
# is empty. Given a list a, your task is to chop off its first and its last element until it 
# becomes beautiful. Implement a function that will make the given a beautiful as described, 
# and return the resulting list as an answer.

# Hint: one of the features introduced in Python 3 called extended unpacking could help here.

# Example

    # For a = [3, 4, 2, 4, 38, 4, 5, 3, 2], the output should be
    # solution(a) = [4, 38, 4].

    # Here's how the answer is obtained:
    # [3, 4, 2, 4, 38, 4, 5, 3, 2] => [4, 2, 4, 38, 4, 5, 3] => [2, 4, 38, 4, 5] => [4, 38, 4].

    # For a = [1, 4, -5], the output should be
    # solution(a) = [4].

# Input/Output

    # [execution time limit] 4 seconds (py3)

    # [input] array.integer a

    # A list of integers.

    # Guaranteed constraints:
    # 0 ≤ a.length ≤ 50,
    # 1 ≤ a[i] ≤ 100.

    # [output] array.integer

    # A beautiful list obtained as described above.


def solution(a):
    res = a[:]
    while res and res[0] != res[-1]:
       a, *res, b = res
    return res



if __name__ == "__main__":
# program starts here, methods are defined above
	print("list [3, 4, 2, 4, 38, 4, 5, 3, 2] results in ", solution([3, 4, 2, 4, 38, 4, 5, 3, 2]))
	print("list [1, 4, -5] results in ", solution([1, 4, -5]))
	print("list [] results in ", solution([]))
	print("list [8] results in ", solution([8]))
	print("list [10, 2, 10, 9, 7, 3, 8, 5, 3, 2, 8, 7] results in ", solution([10, 2, 10, 9, 7, 3, 8, 5, 3, 2, 8, 7]))
	print("list [8, 5, 1, 2, 3, 8, 1, 10, 5, 1, 4, 6, 9, 2, 8, 8, 9, 4, 10, 3] results in ", solution([8, 5, 1, 2, 3, 8, 1, 10, 5, 1, 4, 6, 9, 2, 8, 8, 9, 4, 10, 3]))
	print("list [10, 8, 10] results in ", solution([10, 8, 10]))