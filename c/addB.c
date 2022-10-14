#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
Given a rectangular matrix of characters, add a border of asterisks(*) to it.

Example

For

picture = ["abc",
           "ded"]

the output should be

solution(picture) = ["*****",
                      "*abc*",
                      "*ded*",
                      "*****"]

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.string picture

    A non-empty array of non-empty equal-length strings.

    Guaranteed constraints:
    1 ≤ picture.length ≤ 100,
    1 ≤ picture[i].length ≤ 100.

    [output] array.string

    The same matrix of characters, framed with a border of asterisks of width 1.
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

typedef struct arr_name {
   int size;
   char **arr;
} arr_string;

arr_string alloc_arr_name(int len) {
  arr_string a = {len, len > 0 ? malloc(sizeof(char **) * len) : NULL};
  return a;
}


arr_string solution(arr_string picture) {
	int i,len;
	static char arr[100][100];
	static arr_string myarr={100,arr};
	// clear out temp array
	for(i=0; i<picture.size+2; i++)
		myarr.arr[i][0]='*';
	// get length of string
	len=strlen(picture.arr[0]);
	// initialize first/last string with *
	for(i=0; i<len+2; i++){
		myarr.arr[0][i]='*';
		myarr.arr[picture.size+1][i]='*';
	}
	for(i=0; i<picture.size; i++){
		strcpy(&myarr.arr[i+1][1],picture.arr[i]);
		myarr.arr[i+1][len+1]='*';
	}
	for(i=0; i<picture.size; i++)
		strcpy(picture.arr[i],myarr.arr[i]);
	return myarr;
}

void main()
{

	int i;
	
	arr_string a=alloc_arr_name(2);
	char test_array1[10][100]={"abc","def"};
	//test_array1[0]="abc"; test_array1[1]="def";
	//a.size=4; 
	for(i=0; i<a.size; i++)
		a.arr[i]=test_array1[i];
	
	a=solution(a);
	printf("input array=[abc,def]\n");
	for(i=0; i<a.size; i++)
		printf("%s\n",a.arr[i]);

}