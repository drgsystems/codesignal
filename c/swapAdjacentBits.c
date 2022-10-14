#include <stdio.h>
#include <stdlib.h>

/*
Implement the missing code, denoted by ellipses. You may not 
modify the pre-existing code.

You're given an arbitrary 32-bit integer n. Take its binary 
representation, split bits into it in pairs (bit number 0 and 1, 
bit number 2 and 3, etc.) and swap bits in each pair. Then return 
the result as a decimal number.

Example

    For n = 13, the output should be
    solution(n) = 14.

    13 decimal = 1101 power of 2 ~> {11}{01} power of 2 ~> 1110 power of 2 = 14 decimal.

    For n = 74, the output should be
    solution(n) = 133.

    74 decimal = 01001010 power of 2 ~> {01}{00}{10}{10} power of 2 ~> 10000101 power of 2 = 133 decimal.
    Note the preceding zero written in front of the initial 
	number: since both numbers are 32-bit integers, they have 
	32 bits in their binary representation. The preceding zeros in 
	\other cases don't matter, so they are omitted. Here, however, 
	it does make a difference.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    0 ≤ n < 2 to 30th.

    [output] integer


int solution(int n) {
  return ...;
}

*/
int solution(int n) {

	return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
}

int main()
{
	printf("swap bits for hex %x=%x\n",74,solution(74));

}
