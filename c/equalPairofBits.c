#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.

You're given two integers, n and m. Find position of the rightmost pair of equal bits in their binary representations (it is guaranteed that such a pair exists), counting from right to left.

Return the value of 2position_of_the_found_pair (0-based).

Example

For n = 10 and m = 11, the output should be
solution(n, m) = 2.

1010 = 10102, 1110 = 10112, the position of the rightmost 
pair of equal bits is the bit at position 1 (0-based) from 
the right in the binary representations.
So the answer is 21 = 2.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    0 ≤ n ≤ 230.

    [input] integer m

    Guaranteed constraints:
    0 ≤ m ≤ 230.

    [output] integer
*/
/*
supposed c++ solution
function equalPairOfBits(n, m) {
  return (
    1 <<
    (
      (n ^ m)
        .toString(2)
        .split("")
        .reverse()
        .join("") + "0"
    ).indexOf("0")
  );
}
*/
// works 8 out of 10  return ((n==0&&m==0 ? 1:(n&m) & -(n&m)));

int solution(int n, int m) {
	return (~(n^m)&((n^m)|(n^m)+1));
}

// (~($n^$m)&(($n^$m)|($n^$m)+1))
int main() 
{

	printf("%d\n",solution(0,0));
	printf("%d\n",solution(1073741824,1006895103));
	printf("%d\n",solution(10,11));
}
