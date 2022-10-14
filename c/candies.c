#include "stdio.h"

/*
n children have got m pieces of candy. They want to eat 
as much candy as they can, but each child must eat exactly 
the same amount of candy as any other child. Determine 
how many pieces of candy will be eaten by all the children 
together. Individual pieces of candy cannot be split.

Example

For n = 3 and m = 10, the output should be
solution(n, m) = 9.

Each child will eat 3 pieces. So the answer is 9.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer n
    The number of children.
    Guaranteed constraints:
    1 ≤ n ≤ 10.
    [input] integer m
    The number of pieces of candy.
    Guaranteed constraints:
    2 ≤ m ≤ 100.
    [output] integer
    The total number of pieces of candy the children will eat provided they eat as much as they can and all children eat the same amount.
*/

int solution(int n, int m) {
	return(m/n * n);
}

void main()
{
	printf("%d kids had %d candies, so the total even number of candies each ate = %d\n",5,20,solution(5,20));
	printf("%d kids had %d candies, so the total even number of candies each ate = %d\n",3,20,solution(3,20));
}
