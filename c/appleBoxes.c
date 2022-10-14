#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
You have k apple boxes full of apples. Each square box of size 
m contains m × m apples. You just noticed two interesting properties 
about the boxes:

    The smallest box is size 1, the next one is size 2,..., all 
	the way up to size k.
    Boxes that have an odd size contain only yellow apples. Boxes 
	that have an even size contain only red apples.

Your task is to calculate the difference between the number of red 
apples and the number of yellow apples.

Example

For k = 5, the output should be
solution(k) = -15.

There are 1 + 3 * 3 + 5 * 5 = 35 yellow apples and 2 * 2 + 4 * 4 = 20 r
ed apples, making the answer 20 - 35 = -15.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer k

    A positive integer.

    Guaranteed constraints:
    1 ≤ k ≤ 40.

    [output] integer

    The difference between the two types of apples.
*/

int solution(int k) {
	int yellow=0,red=0;
	for(int i=1; i<=k; i++){
		if(i%2)
			yellow+=i*i;
		else
			red+=i*i;		
	}
	return(red-yellow);
}

int main()
{

	printf("for k=5 result=\n",solution(5));
}
