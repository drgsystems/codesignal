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


def solution(s, upperBound):
    found = -1
    for i in range(upperBound):
        if not i in s:
            found = i
            break
    else:
        found = upperBound

    return found



if __name__ == "__main__":
# program starts here, methods are defined above
	print("list [0, 4, 2, 3, 1, 7] with upperBound: 10 should be 5 results in ", solution([0, 4, 2, 3, 1, 7], 10))
	print("list [0, 4, 2, 3, 1, 7] with upperBound: 3 should be 3 results in ", solution([0, 4, 2, 3, 1, 7], 3))
	print("list [] with upperBound: 13 should be 0 results in ", solution([], 13))
	print("list [1, 5, 10, 20, 4, 11, 18, 0, 9, 3, 8, 15, 19, 16, 17, 7, 13, 2, 14] with upperBound: 3 should be 6 results in ", solution([1, 5, 10, 20, 4, 11, 18, 0, 9, 3, 8, 15, 19, 16, 17, 7, 13, 2, 14], 18))
	print("list [60, 81, 54, 10, 70, 56, 9, 7, 38, 43, 49, 33, 45, 52, 75, 26, 59, 19, 35, 12, 30, 36, 41, 79, 6, 53, 24, 63, 5, 20, 76, 62, 34, 78, 67, 8, 18, 2, 1, 25, 42, 69, 17, 50, 57, 28, 80, 39, 77, 51] with upperBound: 47 should be 0 results in ", solution([60, 81, 54, 10, 70, 56, 9, 7, 38, 43, 49, 33, 45, 52, 75, 26, 59, 19, 35, 12, 30, 36, 41, 79, 6, 53, 24, 63, 5, 20, 76, 62, 34, 78, 67, 8, 18, 2, 1, 25, 42, 69, 17, 50, 57, 28, 80, 39, 77, 51],47))
	print("list [21, 18, 2, 17, 3, 8, 16, 20, 4, 5, 6, 11, 10, 13, 14, 12, 15, 9, 7, 1, 0] with upperBound: 18 should be 18 results in ", solution([21, 18, 2, 17, 3, 8, 16, 20, 4, 5, 6, 11, 10, 13, 14, 12, 15, 9, 7, 1, 0], 18))
	