#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Two arrays are called similar if one can be obtained from 
another by swapping at most one pair of elements in one of the arrays.

Given two arrays a and b, check whether they are similar.

Example

    For a = [1, 2, 3] and b = [1, 2, 3], the output should be
    solution(a, b) = true.

    The arrays are equal, no need to swap any elements.

    For a = [1, 2, 3] and b = [2, 1, 3], the output should be
    solution(a, b) = true.

    We can obtain b from a by swapping 2 and 1 in b.

    For a = [1, 2, 2] and b = [2, 1, 1], the output should be
    solution(a, b) = false.

    Any swap of any two elements either in a or in b won't make a and b equal.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] array.integer a
    Array of integers.

    Guaranteed constraints:
    3 ≤ a.length ≤ 105,
    1 ≤ a[i] ≤ 1000.

    [input] array.integer b
    Array of integers of the same length as a.

    Guaranteed constraints:
    b.length = a.length,
    1 ≤ b[i] ≤ 1000.

    [output] boolean
    true if a and b are similar, false otherwise.
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

// current this function is not used in this exercise
void mysort(int arr[], int size)
{
	int i,j,temp=0;
	for(i=0; i<size; i++) {
		for(j=i+1; j<size; j++){
			if(arr[i] > arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
};

#define FALSE 0
#define TRUE 1

typedef struct arr_name {
   int size;
   int *arr;
} arr_integer;

arr_integer alloc_arr_name(int len) {
  arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
  return a;
}

/* bool solution(arr_integer a, arr_integer b) {
	int i,j,temp=0,fail=0;
	if(a.size != b.size) return FALSE;
	for(i=0; i<a.size; i++){
		if(a.arr[i] != b.arr[i]){
			fail+=1;
			for(j=i+1; j<a.size; j++){
				if(b.arr[j]==a.arr[i]){
					if(b.arr[i]==a.arr[j]){
						temp=b.arr[i];
						b.arr[i]=b.arr[j];
						b.arr[j]=temp;;
					}
					else if(j+1<a.size && b.arr[j]==b.arr[j+1]){
					}
					else
						fail+=1;
				}
			}
		}
	}
	if(fail > 1)
		return FALSE;
	else return TRUE;
} */
// compare function, compares two elements used by qsort
int compare (const void * num1, const void * num2) {
   if(*(int*)num1 > *(int*)num2)
    return 1;
   else
    return -1;
}

bool solution(arr_integer a, arr_integer b) {
	int counter=0;
	for (int i=0; i <a.size; i++) {
		if(a.arr[i] != b.arr[i])
			counter++;
	}
	
	if(counter > 2)
		return false;
	
	qsort(a.arr, a.size, sizeof(int), compare);
	qsort(b.arr, b.size, sizeof(int), compare);
	
	for(int i=0; i<a.size; i++)
		if(a.arr[i] != b.arr[i])
			return false;
		
	return true;
}
	
void main()
{

int a[3] = {1, 2, 3};
int b[3] = {1, 2, 3};
int c[3] = {4, 2, 3};
int d[3] = {2, 1, 3};
int e[3] = {4, 4, 2};
int f[3] = {2, 3, 4};
int g[3] = {2, 2, 4};
int h[6]={1, 2, 1, 2, 2, 1};
int i[6]={2, 2, 1, 1, 2, 1};
int j[4]={1, 2, 1, 2};
int k[4]={2, 2, 1, 1};
int l[30]={25,30,24,99,26,9,17,90,10,13,16,88,8,7,4,3,6,18,20,21,42,33,6,25,66,28,14,2,1,6};
int m[30]={88,30,24,99,26,9,17,90,10,13,16,25,8,7,4,3,6,18,20,21,42,33,6,14,66,28,25,2,1,6};
int n[30]={88,30,24,99,26,9,17,90,10,13,16,25,8,7,4,3,6,18,20,21,42,33,6,14,66,28,25,2,1,6};


arr_integer test1=alloc_arr_name(3); test1.arr=a;
arr_integer test2=alloc_arr_name(3); test2.arr=b;

printf("a=b should be True and tests %s\n",solution(test1,test2) ? "True" : "False");
 
test1.arr=a;
test2.arr=d;
printf("a=d should be True and tests %s\n",solution(test1,test2) ? "True" : "False");

test1.arr=c;
test2.arr=e;
printf("c=e? %s\n",solution(test1,test2) ? "True" : "False");

test1.arr=h; test1.size=6;
test2.arr=i; test2.size=6;
printf("h=i should be True and tests %s\n",solution(test1,test2) ? "True" : "False");

test1.arr=j; test1.size=4;
test2.arr=k; test2.size=4;
printf("j=k should be True and tests %s\n",solution(test1,test2) ? "True" : "False");

test1.arr=j; test1.size=4;
test2.arr=m; test2.size=30;
printf("j=m? %s\n",solution(test1,test2) ? "True" : "False");

arr_integer test3=alloc_arr_name(30); test3.arr=m;
arr_integer test4=alloc_arr_name(30); test4.arr=n;
test3.arr=m; test3.size=30;
test4.arr=n; test4.size=30;
printf("m=n should be True and tests %s\n",solution(test3,test4) ? "True" : "False");

test1.arr=l; test1.size=30;
test2.arr=m; test2.size=30;
printf("l=m? %s\n",solution(test1,test2) ? "True" : "False");
}