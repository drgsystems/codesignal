#include <stdio.h>
#include <math.h>

/*
A little child is studying arithmetic. They have just learned 
how to add two integers, written one below another, column by 
column. But the child always forgets about the important 
part - carrying.

Given two integers, your task is to find the result that the 
child will get.

Note: The child had learned from this site, so feel free to 
check it out too if you are not familiar with column addition.

Example

For param1 = 456 and param2 = 1734, the output should be
solution(param1, param2) = 1180.

   456
  1734
+ ____
  1180

The child performs the following operations from right to left:

    6 + 4 = 10 but the child forgets about carrying the 1 and 
	just writes down the 0 in the last column
    5 + 3 = 8
    4 + 7 = 11 but the child forgets about the leading 1 and 
	just writes down 1 under 4 and 7.
    There is no digit in the first number corresponding to the 
	leading digit of the second one, so the child imagines that 0 
	is written before 456. Thus, they get 0 + 1 = 1.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer param1

    A non-negative integer.

    Guaranteed constraints:
    0 ≤ param1 < 105.

    [input] integer param2

    A non-negative integer.

    Guaranteed constraints:
    0 ≤ param2 < 6 · 104.

    [output] integer

    The result that the little child will get by using column addition without carrying.
*/

int solution(int param1, int param2) {
    int result=0,mypow=1;
    if (param1==0) return param2;
    else if(param2==0) return param1;
    else if(param1==0 && param2==0) return 0;
    for (int i=0; i<5; i++){
        result += ((param1%10+param2%10)%10) * mypow;
        param1/=10;
        param2/=10;
		mypow*=10;
		printf("result=%d, param1=%d, param2=%d\n",result,param1,param2);
    }
    return result;
}

int main()
{
	int param1[4]={456,999,54321,54321};
	int param2[4]={1734,999,54321,56789};
	for(int i=0; i<4; i++)
		printf("%d+%d=%d\n",param1[i],param2[i],solution(param1[i],param2[i]));

}
