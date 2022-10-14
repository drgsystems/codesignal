#include <stdio.h>

/*
Given a divisor and a bound, find the largest integer N such that:

    N is divisible by divisor.
    N is less than or equal to bound.
    N is greater than 0.

It is guaranteed that such a number exists.

Example

For divisor = 3 and bound = 10, the output should be
solution(divisor, bound) = 9.

The largest integer divisible by 3 and not larger than 10 is 9.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer divisor
    Guaranteed constraints:
    2 ≤ divisor ≤ 10.
    [input] integer bound
    Guaranteed constraints:
    5 ≤ bound ≤ 100.
    [output] integer

    The largest integer not greater than bound that is divisible by divisor.
*/

int solution(int divisor, int bound) {
	int result=0,i=0;
	for (i=0; i < bound; i++) {
		result=divisor*i;
		if(result>bound)
			return(divisor*(i-1));	
	}
}

void main() 
{
	printf("if divisor=%d and bound=%d, then largest integer divisible by bound = %d\n",3,10,solution(3,10));
	printf("if divisor=%d and bound=%d, then largest integer divisible by bound = %d\n",6,40,solution(6,40));
}
