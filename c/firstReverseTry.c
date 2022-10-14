#include <stdio.h>
#include <stdlib.h>
/*
Reversing an array can be a tough task, especially for a novice programmer. 
Mary just started coding, so she would like to start with something basic 
at first. Instead of reversing the array entirely, she wants to swap just 
its first and last elements.

Given an array arr, swap its first and last elements and return the resulting array.

Example

For arr = [1, 2, 3, 4, 5], the output should be
solution(arr) = [5, 2, 3, 4, 1].

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.integer arr

    Guaranteed constraints:
    0 ≤ arr.length ≤ 50,
    -104 ≤ arr[i] ≤ 104.

    [output] array.integer

    Array arr with its first and its last elements swapped.
*/

typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;
//
/* arr_integer alloc_arr_integer(int len) {
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
  } */


/* arr_integer solution(arr_integer inputArray, int elemToReplace, int substitutionElem) {
    arr_integer result;
    result.size=inputArray.size;
    result.arr=malloc(sizeof(int) * result.size);
    for(int i=0; i<result.size; i++)
        if(inputArray.arr[i]==elemToReplace) result.arr[i]=substitutionElem;
		else result.arr[i]=inputArray.arr[i];
		
    return result;

} */

arr_integer solution(arr_integer arr) {
	int temp;
	if(arr.size<=1) return arr;
	temp=arr.arr[0];
	arr.arr[0]=arr.arr[arr.size-1];
	arr.arr[arr.size-1]=temp;
	return(arr);
}

int main()
{

	int test1[]={23, 54, 12, 3, 4, 56, 23, 12, 5, 324};
	arr_integer result; result.size=10; result.arr=malloc(sizeof(int) * result.size);
	for(int i=0; i<result.size; i++) result.arr[i]=test1[i];;
		result=solution(result);
	printf("test1 result=%d, %d\n",result.arr[0],result.arr[result.size-1]);
}