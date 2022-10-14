#include <stdio.h>
#include <math.h>

/*
One night you go for a ride on your motorcycle. At 00:00 
you start your engine, and the built-in timer automatically 
begins counting the length of your ride, in minutes. Off 
you go to explore the neighborhood.

When you finally decide to head back, you realize there's 
a chance the bridges on your route home are up, leaving 
you stranded! Unfortunately, you don't have your watch on 
you and don't know what time it is. All you know thanks 
to the bike's timer is that n minutes have passed since 00:00.

Using the bike's timer, calculate the current time. Return 
an answer as the sum of digits that the digital timer in 
the format hh:mm would show.

Example

    For n = 240, the output should be
    solution(n) = 4.

    Since 240 minutes have passed, the current time is 04:00. 
    The digits sum up to 0 + 4 + 0 + 0 = 4, which is the answer.

    For n = 808, the output should be
    solution(n) = 14.
    808 minutes mean that it's 13:28 now, so the answer 
    should be 1 + 3 + 2 + 8 = 14.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer n
    The duration of your ride, in minutes. It is guaranteed 
    that you've been riding for less than a day (24 hours).
    Guaranteed constraints:
    0 ≤ n < 60 · 24.
    [output] integer
    The sum of the digits the digital timer would show.
	
Syntax Tips

// Prints help message to the console
// Returns a string
char * helloWorld(char * name) {
    char * answer = malloc(strlen(name) + 8);
    printf("This prints to the console when you Run Tests");
    strcpy(answer, "Hello, ");
    strcat(answer, name);
    return answer;
}


*/


int solution(int mynum) {
	// check if greater than 12 hours
/* 	float time=mynum;
	// limit to 2 digits fractional
	if(time>1380)
		time=time-720;
	else if(time>60)
		time = (time/60.0)*100;
	printf("time=%.2f\n",time);	
	int num=mynum,sum=0;
sum);	while((int)time != 0){
		int digit = (int) time % 10;
		time = time / 10;
		sum+=digit;
		printf("digit=%d,sum=%d\n", digit, sum);
        }
    return( */
	int hrs=mynum/60;
	int min=mynum%60;
	return(hrs/10 +hrs%10 +min/10 +min%10);
}

void main()
{

    printf("digits in 240=%d, should be 4\n",solution(240));
    printf("digits in 808=%d, should be 14\n",solution(808));
	printf("digits in 1439=%d, should be 19\n",solution(1439));
	printf("digits in 23=%d, should be 5\n",solution(23));
	printf("digits in 8=%d, should be 8\n",solution(8));
	printf("digits in 0=%d, should be 0\n",solution(0));
	printf("digits in 1440=%d, should be 6\n",solution(1440));
	printf("digits in 720=%d, should be 3\n",solution(720));
	printf("digits in 61=%d, should be 2\n",solution(61));
}
