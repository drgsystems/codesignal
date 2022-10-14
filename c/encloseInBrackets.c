#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/*
Given a string, enclose it in round brackets.

Example

For inputString = "abacaba", the output should be
solution(inputString) = "(abacaba)".

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string inputString

    Guaranteed constraints:
    0 ≤ inputString.length ≤ 10.

    [output] string
*/

char * solution(char * inputString) {
	char* result=malloc((strlen(inputString)+2) * sizeof(char));
	result[0]='(';
	for (int i=0; i, inputString[i]!='\0'; i++)
		result[i+1]=inputString[i];
	result[(strlen(inputString)+1)]=')';
	return result;
}

int main()
{

	char* test[10]={"abacaba","abcdef","aaad","if","it","doesnt","challenge","you","itt","wont"};
	char *result;
	
	for(int i=0; i<10; i++){
		result = solution(test[i]);
		for(int j=0; result[j]!='\0'; j++)
			printf("%c",result[j]);
		printf("\n");
	}
}
