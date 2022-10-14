#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/*
Imagine a white rectangular grid of n rows and m columns divided 
into two parts by a diagonal line running from the upper left to 
the lower right corner. Now let's paint the grid in two colors 
according to the following rules:

    A cell is painted black if it has at least one point in common 
	with the diagonal;Otherwise, a cell is painted white.
 
Count the number of cells painted black.

Example

    For n = 3 and m = 4, the output should be
    solution(n, m) = 6.

    There are 6 cells that have at least one common point with 
	the diagonal and therefore are painted black.

    For n = 3 and m = 3, the output should be
    solution(n, m) = 7.

    7 cells have at least one common point with the diagonal and 
	are painted black.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer n

    The number of rows.

    Guaranteed constraints:
    1 ≤ n ≤ 105.

    [input] integer m

    The number of columns.

    Guaranteed constraints:
    1 ≤ m ≤ 105.

    [output] integer

    The number of black cells.

*/
// note first cell on left line runs throught it, so for 
// every other cell from start
// S = M + N - 1 - (gcd(M, N) - 1) = M + N - gcd(M, N)
//
int solution1(int n, int m) {
	if(n==1) return m;
	return n*m;
}
int gcd(int n, int m){
    while (m) {
        int temp = n;
        n = m;
        m = temp%m;
    }
    
    return n;
}
int solution2(int n, int m) {
    if (n == m) return (n + 2*(n-1));
    //if (n == 1 || m==1 ) return n*m;
    return n + m -gcd(n, m) + (gcd(n, m)-1)*2;
}

// I like this solution as easiest
int solution(int n, int m) {
    int max = 1;
    for (int k = 1; k <= n; k++) {
        if (n%k == 0 && m%k == 0)
            max = k;
    }
    return n+m+max-2;
}
int main()
{
	int test1[10][3]={{3,4,6},
					{3,3,7},
					{2,5,6},
					{1,1,1},
					{1,2,2},
					{1,3,3},
					{1,239,239},
					{33,44,86},
					{16,8,30},
					{66666,88888,177774}};
	for (int i=0; i<10; i++)
		printf("test1[%d] = %d,%d, should be %d and is %d\n",i,test1[i][0],test1[i][1],test1[i][2],solution(test1[i][0],test1[i][1]));

}