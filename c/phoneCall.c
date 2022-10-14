#include <stdio.h>

/*
Some phone usage rate may be described as follows:

    first minute of a call costs min1 cents,
    each minute from the 2nd up to 10th (inclusive) costs min2_10 cents
    each minute after 10th costs min11 cents.

You have s cents on your account before the call. What is the duration 
of the longest call (in minutes rounded down to the nearest integer) 
you can have?

Example

For min1 = 3, min2_10 = 1, min11 = 2, and s = 20, the output should be
solution(min1, min2_10, min11, s) = 14.

Here's why:

    the first minute costs 3 cents, which leaves you with 20 - 3 = 17 cents;
    the total cost of minutes 2 through 10 is 1 * 9 = 9, so you can talk 
	9 more minutes and still have 17 - 9 = 8 cents;
    each next minute costs 2 cents, which means that you can talk 8 / 2 = 4 more minutes.

Thus, the longest call you can make is 1 + 9 + 4 = 14 minutes long.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer min1
    Guaranteed constraints:
    1 ≤ min1 ≤ 10.
    [input] integer min2_10
    Guaranteed constraints:
    1 ≤ min2_10 ≤ 10.
    [input] integer min11
    Guaranteed constraints:
    1 ≤ min11 ≤ 10.
    [input] integer s
    Guaranteed constraints:
    2 ≤ s ≤ 500.

    [output] integer
*/

int solution(int min1, int min2_10, int min11, int s) {
	int sec = 0;
	if (s< min1) return(0);
	s-=min1;
	sec++;
	if(s< 9*min2_10){
		sec+= s/min2_10;
		return(sec);
	}
	s-= 9*min2_10;
	sec+=9;
	sec+=s/min11;
	return sec;
}

int solution2(int min1, int min2_10, int min11, int s) {
    int sum=s-min1,i=1;
    if(sum<0) return(0);
    else if(sum==0) return(1);
	else if((sum-min2_10)==0) return(sum+1);
    else{
        printf("sum=%d\n",sum);
		if((min2_10*9)>sum){
			printf("while entry>-sum=%d\n",sum);
/* 			while((sum-(min2_10*i))>=0){
				printf("%d-(%d*%d)=%d\n",sum,min2_10,i,(sum-(min2_10*i)));
*/				if(sum+(sum/min2_10)>s)
					sum-=sum/min2_10;
				else
					sum+=sum/min2_10;
/* 				i+=1;
				printf("while inside>-i=%d,sum=%d\n",i,sum);
			}
 */			printf("while exit>-sum=%d\n",sum);
			return(sum);
		}
			//return(min1+min2_10);
        else if(sum-(min2_10*9)< 0){
			printf("while entry<-sum=%d\n",sum);
			while(sum-(min2_10*i)>0){
				sum=sum+1;
				i+=1;
				printf("while inside<-sum=%d\n",sum);
			}
			printf("while exit<-sum=%d\n",sum);
			return(sum);
		}
        else if(sum-(min2_10*9)< 0)
			return(sum);
		else 
			sum=sum-(min2_10*9);		
		sum=sum/min11;
		printf("sum=%d\n",sum);
    }
	return(10+sum);
}
int solution1(int min1, int min2_10, int min11, int s) {
    int sum=s-min1;
    if(sum<0) return(0);
    else if(sum==0) return(1);
    else{
        printf("sum=%d\n",sum);
        if((min2_10*9)>sum)
            return(min1+min2_10);
        else if(sum-(min2_10*9)< 0)
                        return(sum);
		else 
				sum=sum-(min2_10*9);
        printf("sum=%d\n",sum);
        sum=sum/min11;
        printf("sum=%d\n",sum);
    }
        return(10+sum);
}

void main()
{

	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",3,1,2,20,solution(3,1,2,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",2,2,1,24,solution(2,2,1,24));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",1,2,2,6,solution(1,2,1,6));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",10,10,2,20,solution(10,10,1,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",10,5,2,20,solution(10,5,1,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",9,1,4,20,solution(9,1,4,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",10,10,10,500,solution(10,10,10,500));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",1,1,1,2,solution(1,1,1,2));
 	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",1,1,1,500,solution(1,1,1,500));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",1,10,1,2,solution(1,10,1,2));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n\n",10,10,1,2,solution(10,10,1,2));	
	
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n",3,1,2,20,solution1(3,1,2,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n",2,2,1,24,solution1(2,2,1,24));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n",1,2,2,6,solution1(1,2,1,6));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n",10,10,2,20,solution1(10,10,1,20));
	printf("min1=%d, min2_10=%d, min11=%d, money=%d, total minutes you can call=%d\n",10,5,2,20,solution1(10,5,1,20));

}