#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Implement the missing code, denoted by ellipses. You may not modify 
the pre-existing code.

Presented with the integer n, find the 0-based position of the second 
rightmost zero bit in its binary representation (it is guaranteed that 
such a bit exists), counting from right to left.

Return the value of 2position_of_the_found_bit.

Example

For n = 37, the output should be
solution(n) = 8.

3710 = 1001012. The second rightmost zero bit is at position 3 (0-based) 
from the right in the binary representation of n.
Thus, the answer is 23 = 8.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    4 ≤ n ≤ 230.

    [output] integer





You have to get rid of the rightmost 0
To fill in the rightmost 0 with 1 using x | (x + 1)
    10111100  (x)
|   10111101  (x + 1)
    --------
    10111101
Isolate the new rightmost 0
To isolate it use ~x & (x + 1)
// now x is the value after step 1

    10111101  (x)
    --------
    01000010  (~x)
&   10111110  (x + 1)
    --------
    00000010
 in short 
  return ~(n|(n+1)) & ((n|(n+1))+1) ;
*/
int solution(int n) {
  return ~(n|(n+1)) & ((n|(n+1))+1);
}
int solution1(int n) {
	int a=0;
	printf("n=%x\n",n);
	printf("n|(n+1)=%x\n",n|(n+1));
	printf("~(n|(n+1)=%x\n",~(n|(n+1)));
	printf("(n|(n+1))+1)=%x\n",(n|(n+1))+1);
	printf("~(n|(n+1)) & ((n|(n+1))+1)=%x\n",~(n|(n+1)) & ((n|(n+1))+1));
}
int main()
{
	int n=37;
	int n1=1073741824;
 	int n2=83748;
	//int x=0,a=0;
/*	while(a<2){
		(n&1L ? : a++); n=n>>1; x++;}
		for(int i=0,a=1; i<x-1; i++) {a=a*2;
		printf("result=%d\n",a);} */
	/* 
	printf("result=%d\n", int a<2 ?  : (n&1L ? : a++); n=n>>1; int x++;}
		for(int i=0,a=1; i<x-1; i++) a=a*2); */
		//printf("result=%d\n", ~(n|(n+1)) & ((n|(n+1))+1));
	printf("result=%d\n", solution1(n));
	printf("result=%d\n", solution1(n1));
	printf("result=%d\n", solution1(n2));
}	
	
	