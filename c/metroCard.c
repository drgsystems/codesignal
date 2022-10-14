#include <stdio.h>
#include <stdlib.h>

/*
You just bought a public transit card that allows you to ride the 
Metro for a certain number of days.

Here is how it works: upon first receiving the card, the system 
allocates you a 31-day pass, which equals the number of days in 
January. The second time you pay for the card, your pass is extended 
by 28 days, i.e. the number of days in February (note that leap 
years are not considered), and so on. The 13th time you extend 
the pass, you get 31 days again.

You just ran out of days on the card, and unfortunately you've 
forgotten how many times your pass has been extended so far. 
However, you do remember the number of days you were able to 
ride the Metro during this most recent month. Figure out the 
number of days by which your pass will now be extended, and 
return all the options as an array sorted in increasing order.

Example

For lastNumberOfDays = 30, the output should be
solution(lastNumberOfDays) = [31].

There are 30 days in April, June, September and November, so 
the next months to consider are May, July, October or December. 
All of them have exactly 31 days, which means that you will 
definitely get a 31-days pass the next time you extend your card.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer lastNumberOfDays

    A positive integer, the number of days for which the card was 
	extended the last time.

    Guaranteed constraints:
    lastNumberOfDays = 28 or lastNumberOfDays = 30 or lastNumberOfDays = 31.

    [output] array.integer

    An array of positive integers, the possible number of days for which 
	you will extend your pass. The elements of the array can only be equal 
	to 28, 30 or 31 and must be sorted in increasing order.
*/

// Arrays are already defined with this interface:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//

void printArray(int myarray[], int size) {
	//for (int i = 0; i < sizeof(myarray) / sizeof(int); ++i)
	for (int i = 0; i < size; ++i)
		printf("%i", myarray[i]);
		printf("\n");
}
	
typedef struct arr_integer {
   int size;
   int *arr;
} arr_integer;

arr_integer alloc_arr_integer(int len) {
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
}
  
arr_integer solution(int lastNumberOfDays) {
    arr_integer result;
    if (lastNumberOfDays<=30) {
        result.size=1; 
        result.arr[0]=31;
        //printf("%i\n",result.arr[0]);
    }
    else {
        result.size=3;
        result.arr[0]=28;
        result.arr[1]=30;
        result.arr[2]=31;
/* 		printf("%d\n",result.arr[0]);
		printf("%d\n",result.arr[1]);
		printf("%d\n",result.arr[2]); */
    }

    return(result);
}

int main()
{
	arr_integer result;
	printf("myarray for %d = \n",30);
	result=solution(30);
	printArray(result.arr,1);
	
}