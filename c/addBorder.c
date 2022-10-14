#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	for(i=0; i<100; i++)
		for(len=0; len<100; len++)
			arr[i][len]=NULL;
	arr_string result=alloc_arr_name(picture.size+2);
	// clear out temp array
	for(i=0; i<picture.size+2; i++)
		arr[i][0]='*';
	// get length of string
	len=strlen(picture.arr[0]);
	// initialize first/last string with *
	for(i=0; i<len+2; i++){
		arr[0][i]='*';
		arr[picture.size+1][i]='*';
	}
	for(i=0; i<picture.size; i++){
		strcpy(&arr[i+1][1],picture.arr[i]);
		arr[i+1][len+1]='*';
	}
	len=picture.size+(sizeof(char**)*2);
	//free(picture.arr);
	result.size=picture.size+2;
	for(i=0; i<result.size; i++)
		result.arr[i]=arr[i];
	return result;
}

void main()
{

	int i;
	
	arr_string a=alloc_arr_name(2);
	char test_array1[10][100]={"abc","def"};
 
	for(i=0; i<a.size; i++)
		a.arr[i]=test_array1[i];
	
	a=solution(a);
	printf("input array=[abc,def]\n");
	for(i=0; i<a.size; i++)
		printf("%s\n",a.arr[i]);
	
	char test_array2[10][100]={"a"};
	a.size=1;
	for(i=0; i<a.size; i++)
		a.arr[i]=test_array2[i];
	
	a=solution(a);
	printf("input array=[a]\n");
	for(i=0; i<a.size; i++)
		printf("%s\n",a.arr[i]);
	
}