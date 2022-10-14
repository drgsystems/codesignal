#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/*
We want to turn the given integer into a number that has only 
one non-zero digit using a tail rounding approach. This means 
that at each step we take the last non 0 digit of the number 
and round it to 0 or to 10. If it's less than 5 we round it to 0 
if it's larger than or equal to 5 we round it to 10 (rounding 
to 10 means increasing the next significant digit by 1). 
The process stops immediately once there is only one non-zero 
digit left.

Example

    For n = 15, the output should be
    solution(n) = 20;

    For n = 1234, the output should be
    solution(n) = 1000.

    1234 -> 1230 -> 1200 -> 1000.

    For n = 1445, the output should be
    solution(n) = 2000.

    1445 -> 1450 -> 1500 -> 2000.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer n

    A positive integer.

    Guaranteed constraints:
    1 ≤ value ≤ 108.

    [output] integer

    The rounded number.
*/

int solution(int n) {
	int mypow=1,result=n;
	while(n>10){
		if(n%10<5) result-= n%10 * mypow;
		else {
			result+= (10-n%10) * mypow;
			n+= (10-n%10);
		}
		mypow *= 10;
		n/=10;
		printf("result=%d, n=%d\n",result,n);
	}
	return result;
}

int main()
{
	int test1[7]={15,1234,1445,14,10,7001,99};
	for(int i=0; i<7; i++)
		printf("for %d the result is %d\n",test1[i],solution(test1[i]));

}
