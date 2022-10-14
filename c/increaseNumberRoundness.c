#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
Define an integer's roundness as the number of trailing zeroes in it.

Given an integer n, check if it's possible to increase n's roundness 
by swapping some pair of its digits.

Example

    For n = 902200100, the output should be
    solution(n) = true.

    One of the possible ways to increase roundness of n is to swap digit 
	1 with digit 0 preceding it: roundness of 902201000 is 3, and roundness 
	of n is 2.

    For instance, one may swap the leftmost 0 with 1.

    For n = 11000, the output should be
    solution(n) = false.

    Roundness of n is 3, and there is no way to increase it.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer n

    A positive integer.

    Guaranteed constraints:
    100 ≤ n ≤ 109.

    [output] boolean

    true if it's possible to increase n's roundness, false otherwise.

*/
#define TRUE 1
#define FALSE 0

bool solution(int n) {
    int mymod;
	while (n!=0){
        mymod=n%100;
		if(mymod>0 && mymod<=9 && n>10) return TRUE;
		n/=10;
	}
	return(FALSE);
}

int main()
{

	printf("for n=902200100 result=%s\n",(solution(902200100)? "true" : "false"));
}
