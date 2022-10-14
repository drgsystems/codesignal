#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Let's say that number a feels comfortable with number b if a ≠ b and 
b lies in the segment [a - s(a), a + s(a)], where s(x) is the sum of 
x's digits.

How many pairs (a, b) are there, such that a < b, both a and b lie 
on the segment [l, r], and each number feels comfortable with the 
other (so a feels comfortable with b and b feels comfortable with a)?

Example

For l = 10 and r = 12, the output should be
solution(l, r) = 2.

Here are all values of s(x) to consider:

    s(10) = 1, so 10 is comfortable with 9 and 11;
    s(11) = 2, so 11 is comfortable with 9, 10, 12 and 13;
    s(12) = 3, so 12 is comfortable with 9, 10, 11, 13, 14 and 15.

Thus, there are 2 pairs of numbers comfortable with each other within 
the segment [10; 12]: (10, 11) and (11, 12).

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer l

    Guaranteed constraints:
    1 ≤ l ≤ r ≤ 1000.

    [input] integer r

    Guaranteed constraints:
    1 ≤ l ≤ r ≤ 1000.

    [output] integer

    The number of pairs satisfying all the above conditions.
*/

int cnt_digits(int a) {
    int digit=0;
    while(a!=0) {
        digit+=a%10;
        a/=10;
    }
    return digit;    
}

bool comfortable(int a, int b)
{
	//printf("a=%d, b=%d\n",a,b);
    return b >= a - cnt_digits(a) && b <= a + cnt_digits(a);
}

int solution(int l, int r) {
    int res = 0,a,b;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
			a=comfortable(i,  j); b=comfortable(j,  i);
			printf("a=%d,b=%d\n", a, b);
			if(a && b) {
            //if (comfortable(i,  j) && comfortable(j, i)) {
                ++res;
            }
        }
    }        
    return res;
}


int main()
{

	int test[6][3]={{10,12,2},
				{1,9,20},
				{13,13,0},
				{12,108,707},
				{239,777,6166},
				{1,1000,11435}};
	for(int i=0; i<6; i++)
		printf("L=%d, R=%d, should be %d and is %d\n",test[i][0],test[i][1], test[i][2],solution(test[i][0],test[i][1]));


}
