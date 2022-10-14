#include <stdio.h>
#include <stdlib.h>
/*
Given two arrays of integers a and b, obtain the array formed 
by the elements of a followed by the elements of b.

Example

For a = [2, 2, 1] and b = [10, 11], the output should be
solution(a, b) = [2, 2, 1, 10, 11].

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.integer a

    Guaranteed constraints:
    1 ≤ a.length ≤ 10,
    1 ≤ a[i] ≤ 15.

    [input] array.integer b

    Guaranteed constraints:
    0 ≤ b.length ≤ 10,
    1 ≤ b[i] ≤ 15.

    [output] array.integer

*/

typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;


/* arr_integer solution(arr_integer inputArray, int elemToReplace, int substitutionElem) {
    arr_integer result;
    result.size=inputArray.size;
    result.arr=malloc(sizeof(int) * result.size);
    for(int i=0; i<result.size; i++)
        if(inputArray.arr[i]==elemToReplace) result.arr[i]=substitutionElem;
		else result.arr[i]=inputArray.arr[i];
		
    return result;

} */

/* arr_integer solution(arr_integer arr) {
	int temp;
	if(arr.size<=1) return arr;
	temp=arr.arr[0];
	arr.arr[0]=arr.arr[arr.size-1];
	arr.arr[arr.size-1]=temp;
	return(arr);
} */

/* int main()
{

	int test1[]={23, 54, 12, 3, 4, 56, 23, 12, 5, 324};
	arr_integer result; result.size=10; result.arr=malloc(sizeof(int) * result.size);
	for(int i=0; i<result.size; i++) result.arr[i]=test1[i];;
		result=solution(result);
	printf("test1 result=%d, %d\n",result.arr[0],result.arr[result.size-1]);
} */

arr_integer solution(arr_integer a, arr_integer b) {
	arr_integer result; result.size=a.size+b.size; result.arr=malloc(sizeof(int) * result.size);
	for(int i=0; i<result.size; i++)
		if(i<a.size) result.arr[i]=a.arr[i];
		else result.arr[i]=b.arr[i-a.size];
	return result;
}
int main()
{
	
	
}