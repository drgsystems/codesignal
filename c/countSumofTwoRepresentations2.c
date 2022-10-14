#include <stdio.h>

/*
Given integers n, l and r, find the number of ways to represent 
n as a sum of two integers A and B such that l ≤ A ≤ B ≤ r.

Example

For n = 6, l = 2, and r = 4, the output should be
solution(n, l, r) = 2.

There are just two ways to write 6 as A + B, 
where 2 ≤ A ≤ B ≤ 4: 6 = 2 + 4 and 6 = 3 + 3.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer n
    A positive integer.
    Guaranteed constraints:
    5 ≤ n ≤ 109.
    [input] integer l
    A positive integer.
    Guaranteed constraints:
    1 ≤ l ≤ r.
    [input] integer r
    A positive integer.
    Guaranteed constraints:
    l ≤ r ≤ 109,
    r - l ≤ 106.
    [output] integer

*/
/*
int solution(int n, int l, int r) {
     int result=0;
 	printf("n=%d, l=%d, r=%d, r-l=%d\n",n,l,r,r-l);
	int i=0;
	if(l==r) return 1;
	else if(n<l || n<r) return 0;
	else
		if(result=n-r > l) result=n-r-l+1;
		else if(n-r==l)
			result=l/2+1;
		else result=n-r;
	printf("result=%d\n",result);

    return result;
}
*/
int solution(int n, int l, int r) {
    int result=0;
    //if(l+r==n) return 1;
	printf("n=%d, l=%d,r=%d\n",n,l,r);
	int half=n/2,range=(n-r);result=half-range;
	if(n<l || n<r) return 0;
	return result+1;
}
/* 	printf("n=%d, l=%d, r=%d, r-l=%d\n",n,l,r,r-l);
	int i=0;
	if(l==r) return 1;
	else if(n<l || n<r) return 0;
	else
		if(result=n-r > l) result=n-r-l+1;
		else if(n-r==l)
			result=l/2+1;
		else result=n-r;
	printf("result=%d\n",result); 

    return result;
}*/

int main()
{
	int test1[]={6,2,4,2};
	int test2[]={6,3,3,1};
	int test3[]={10,9,11,0};
	int test4[]={24,8,16,5};
	int test5[]={24,12,12,1};
	int test6[]={93,24,58,12};
	
	printf("test1[]={6,2,4,2}, result=%d\n",solution(test1[0],test1[1],test1[2]));
	printf("test2[]={6,3,3,1}, result=%d\n",solution(test2[0],test2[1],test2[2]));
	printf("test3[]={10,9,11,0}, result=%d\n",solution(test3[0],test3[1],test3[2]));
	printf("test4[]={24,8,16,5}, result=%d\n",solution(test4[0],test4[1],test4[2]));
	printf("test5[]={24,12,12,1}, result=%d\n",solution(test5[0],test5[1],test5[2]));
	printf("test6[]={93,24,58,12}, result=%d\n",solution(test6[0],test6[1],test6[2]));
}
