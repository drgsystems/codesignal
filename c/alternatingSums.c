#include <stdio.h>
#include <stdlib.h>

/*

Several people are standing in a row and need to be 
divided into two teams. The first person goes into 
team 1, the second goes into team 2, the third goes 
into team 1 again, the fourth into team 2, and so on.

You are given an array of positive integers - the 
weights of the people. Return an array of two integers, 
where the first element is the total weight of team 1, 
and the second element is the total weight of team 2 
after the division is complete.

Example

For a = [50, 60, 60, 45, 70], the output should be
solution(a) = [180, 105].

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.integer a

    Guaranteed constraints:
    1 ≤ a.length ≤ 105,
    45 ≤ a[i] ≤ 100.

    [output] array.integer
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
//
typedef struct arr_integer {
	int size;
	int *arr;
 } arr_integer;
 
arr_integer alloc_arr_integer(int len) {
	arr_integer a = {len, len > 0 ? malloc(sizeof(int *) * len) : NULL};
	return a;
 }


arr_integer solution(arr_integer a) {
	int i;
	static int arr[2]={0,0};
	static arr_integer result={2,arr};
	result.arr[0]=0; result.arr[1]=0;
	for(i=0; i<a.size; i++){
		if (i% 2 == 0)
			result.arr[0]+=a.arr[i];
		else
			result.arr[1]+=a.arr[i];
		printf("a.size=%d, a.arr[%d]=%d, result.arr[0]=%d, result.arr[1]=%d\n",a.size, i,a.arr[i],result.arr[0],result.arr[1]);
		}
	return(result);
}

void main()
{
	arr_integer a=alloc_arr_integer(6);
	
	int test_array1[]={50,60,60,45,70};
	a.size=6; a.arr=test_array1;
	
	a=solution(a);
	printf("input array=[50,60,60,45,70], return array=[%d,%d]]\n",a.arr[0],a.arr[1]);


	int test_array2[]={15,25,19,44,33,10};
	a.size=6; a.arr=test_array2;
	
	a=solution(a);
	printf("input array=[15,25,19,44,33,10], return array=[%d,%d]]\n",a.arr[0],a.arr[1]);

	
	arr_integer b=alloc_arr_integer(11);
	int test_array3[]={6,8,1,0,2,5,7,9,22,555,678};
	b.size=11; b.arr=test_array3;

	b=solution(b);
	printf("input array=[6,8,1,0,2,5,7,9,22,555,678], return array=[%d,%d]]\n",b.arr[0],b.arr[1]);
	
}