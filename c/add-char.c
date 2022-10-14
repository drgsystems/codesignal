#include <stdio.h>

int main()
{

	char char1[5],char2[5];
	while(char1[0]!='/' || char2[0]!='/'){
		printf("input char1: ");
		scanf("%1s",char1);
		printf("input char2: ");
		scanf("%1s",char2);
		printf(" %c + %c = %d\n",char1[0],char2[0],char1[0]+char2[0]);
		printf(" %c - %c = %d\n",char1[0],char2[0],char1[0]-char2[0]);
	}
}