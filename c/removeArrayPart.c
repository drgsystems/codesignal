#include <stdio.h>
#include <stdlib.h>

/*
make a duplicate of array except for whats in range left to right
*/

typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;

arr_integer solution(arr_integer inputArray, int l, int r) {
    arr_integer result; 

	result.size=inputArray.size-(r-l)-1;
    printf("l=%d, r=%d, inputArray.size=%d, result.size=%d\n",l,r,inputArray.size,result.size);
    result.arr=malloc(sizeof(int) * result.size);
    for(int i=0,j=0; i<inputArray.size; i++)
		if(i<l || i>r)
        result.arr[j++]=inputArray.arr[i];

    
    return result;
}

int main()
{
	int test1[6]={2, 3, 2, 3, 4, 5}, L1=2,R1=4; // [2,3,5]
	int test2[4]={2, 4, 10, 1}, L2=0, R2=2; // [1]
	int test3[]={5, 3, 2, 3, 4}, L3=1, R3=1; // [5, 2, 3, 4]
	arr_integer result; 
	int i;
	result.size=sizeof(test1)/sizeof(int); 
	result.arr=malloc(sizeof(int) * result.size);

	for(i=0; i<result.size; i++) 
		result.arr[i]=test1[i];
	result=solution(result,L1,R1);
	for(i=0; i< result.size; i++)
		printf("result.arr[%d]=%d ",i,result.arr[i]);
	printf("\n");
}