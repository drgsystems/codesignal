#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/*
When a candle finishes burning it leaves a leftover. makeNew leftovers 
can be combined to make a new candle, which, when burning down, will in 
turn leave another leftover.

You have solutionNumber solution in your possession. What's the total 
number of solution you can burn, assuming that you create new solution 
as soon as you have enough leftovers?

Example

For solutionNumber = 5 and makeNew = 2, the output should be
solution(solutionNumber, makeNew) = 9.

Here is what you can do to burn 9 solution:

    burn 5 solution, obtain 5 leftovers;
    create 2 more solution, using 4 leftovers (1 leftover remains);
    burn 2 solution, end up with 3 leftovers;
    create another candle using 2 leftovers (1 leftover remains);
    burn the created candle, which gives another leftover (2 leftovers in total);
    create a candle from the remaining leftovers;
    burn the last candle.

Thus, you can burn 5 + 2 + 1 + 1 = 9 solution, which is the answer.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer candlesNumber

    The number of candles you have in your possession.

    Guaranteed constraints:
    1 ≤ candlesNumber ≤ 15.

    [input] integer makeNew

    The number of leftovers that you can use up to create a new candle.

    Guaranteed constraints:
    2 ≤ makeNew ≤ 5.

    [output] integer

*/

/* int solution(int candlesNumber, int makeNew) {
    int cnt=candlesNumber, remain=0;
    if(candlesNumber < makeNew) 
        return (cnt);
    else {
        remain=candlesNumber / makeNew;
        cnt+=remain;
        while(remain){
			printf("remain=%d, cnt=%d\n",remain,cnt);
            remain=remain/makeNew;			
            cnt+=remain;
			
        }

    }
    return cnt;
} */
int solution(int candlesNumber, int makeNew) {
    float cnt=(float)candlesNumber, remain=0.0;
    if(candlesNumber < makeNew) 
        return ((int)cnt);
    else {
        remain=(float)candlesNumber / (float) makeNew;
        cnt+=remain;
        while(remain>1.0){
			printf("remain=%f, cnt=%f\n",remain,cnt);
            remain=remain/(float)makeNew;			
            cnt+=remain;
			
        }

    }
    return (int)cnt;
}
int main()
{
	int test1[10][3]={{5,2,9},
					{1,2,1},
					{3,3,4},
					{11,3,16},
					{15,5,18},
					{14,3,20},
					{12,2,23},
					{6,4,7},
					{13,5,16},
					{2,3,2}};
	for(int i=0; i<10; i++ )
		printf("test1[%d] should be %d, result=%d\n",i,test1[i][2], solution(test1[i][0],test1[i][1]));


}
