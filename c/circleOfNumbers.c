#include <stdio.h>

/*
Consider integer numbers from 0 to n - 1 written down 
along the circle in such a way that the distance between 
any two neighboring numbers is equal (note that 0 and 
n - 1 are neighboring, too).

Given n and firstNumber, find the number which is written 
in the radially opposite position to firstNumber.

Example

For n = 10 and firstNumber = 2, the output should be
solution(n, firstNumber) = 7.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer n
    A positive even integer.
    Guaranteed constraints:
    4 ≤ n ≤ 20.
    [input] integer firstNumber
    Guaranteed constraints:
    0 ≤ firstNumber ≤ n - 1.
    [output] integer
*/

int solution(int n, int firstNumber) {
    if (firstNumber >= (n / 2))
        return (firstNumber - (n / 2));
    return (firstNumber + (n / 2));
}

void main()
{

	printf("n=%d, firstNumber=%d, solution=%d\n",10,2,solution(10,2));
        printf("n=%d, firstNumber=%d, solution=%d\n",6,3,solution(6,3));

}
