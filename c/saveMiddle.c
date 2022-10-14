#include <stdio.h>
#include <stdlib.h>

/*
We define the middle of the array arr as follows:

    if arr contains an odd number of elements, its middle is the 
	element whose index number is the same when counting from the 
	beginning of the array and from its end;
    if arr contains an even number of elements, its middle is the 
	sum of the two elements whose index numbers when counting from 
	the beginning and from the end of the array differ by one.

Given array arr, your task is to find its middle, and, if it consists 
of two elements, replace those elements with the value of middle. 
Return the resulting array as the answer.

Example

    For arr = [7, 2, 2, 5, 10, 7], the output should be
    solution(arr) = [7, 2, 7, 10, 7].

    The middle consists of two elements, 2 and 5. These two elements 
	should be replaced with their sum, i.e. 7.

    For arr = [-5, -5, 10], the output should be
    solution(arr) = [-5, -5, 10].

    The middle is defined as a single element -5, so the initial array 
	with no changes should be returned.
*/

typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;

int main()
{
 
	int test[6]={7,2,2,5,10,7}; 
	
	arr_integer arr; 
	arr.size=sizeof(test)/sizeof(int);
	arr.arr=malloc(sizeof(int) * arr.size);
	for(int x=0; x<arr.size; x++)
		arr.arr[x]=test[x];
//========================================================	
    arr_integer result; result.size=arr.size%2==0 ? arr.size-1 : arr.size; 
     result.arr=malloc(sizeof(int) * result.size);
     
    printf("arr.size=%d, &arr.arr=%p, result.size=%d,&result.arr=%p\n",arr.size,&arr.arr[0],result.size,&result.arr[0]);
    
    for(int i=0; i<result.size; i++){
        if(i==result.size/2 && arr.size%2==0){
            result.arr[i]=arr.arr[i+1]+arr.arr[i];
            printf("if, %d, %d\n",result.arr[i],arr.arr[i+1]+arr.arr[i]);
        }
        else if(i>result.size/2 && arr.size%2==0){ 
            result.arr[i]=arr.arr[i+1];
            printf("else if, %d, %d\n",result.arr[i],arr.arr[i+1]+arr.arr[i]);
        }
        else {
            result.arr[i]=arr.arr[i];
            printf("else, %d, %d\n",result.arr[i],arr.arr[i+1]+arr.arr[i]);
        }
        
    }
	printf("result.arr= ");
	for(int j=0; j<result.size; j++)
		printf("%d ",result.arr[j]);
	printf("\n");
    //return result;
}