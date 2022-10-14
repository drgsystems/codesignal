#include "stdio.h"
#include "math.h"

unsigned long test(int n)
{
	unsigned long base=10,result=10,exp=n;

	if(exp==0) return(0);
	while (exp != 1) {
	result *= base;
        --exp;
    } 
	return(result-1);
}

void main()
{
int number;
printf("test return value=%ld\n", test(2));
printf("test return value=%ld\n", test(9));
printf("enter a number: ");
scanf("%d",&number);
printf("test return value=%ld\n",test(number));
}

