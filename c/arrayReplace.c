#include <stdio.h>
#include <stdlib.h>


typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;
//
/* arr_integer alloc_arr_integer(int len) {
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
  } */

arr_integer solution1(int size) {
    arr_integer result;
    result.size=size;
    result.arr=malloc(sizeof(int) * size);
    for(int i=0; i<size; i++)
        result.arr[i]=1;
    return result;

}
arr_integer solution(arr_integer inputArray, int elemToReplace, int substitutionElem) {
    arr_integer result;
    result.size=inputArray.size;
    result.arr=malloc(sizeof(int) * result.size);
    for(int i=0; i<result.size; i++)
        if(inputArray.arr[i]==elemToReplace) result.arr[i]=substitutionElem;
		else result.arr[i]=inputArray.arr[i];
		
    return result;

}

int main()
{

	int test1[]={1, 2, 1}, elem1=1,repl=3;
	arr_integer result; result.size=3; result.arr=malloc(sizeof(int) * result.size);
	for(int i=0; i<result.size; i++) result.arr[i]=test1[i];;
	result=solution(result, elem1, repl);
	printf("test1 result=%d, %d, %d\n",result.arr[0],result.arr[1],result.arr[2]);
}