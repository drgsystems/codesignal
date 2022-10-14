#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arr_string {
	int size;
	char *arr[4];
} arr_string;
  
void pswap(char* l, char* r) {
    char* temp = l;
    l = r;
    r = temp;
}

void reverse(char* A, char* B) {
	int l=0, r=3;
	while (l < r) {
        pswap(&A[l++], &B[r--]);
    }
}
  
bool next_permutation(char* begin, char* end)  
{  
        if (begin == end)  
                return false;  
  
        char* i = begin;  
        ++i;  
        if (i == end)  
                return false;  
  
        i = end;  
        --i;  
  
        while (true)  
        {  
                char* j = i;  
                --i;  
  
                if (*i < *j)  
                {  
                        char* k = end;  
  
                        while (!(*i < *--k))  
                                /* pass */;  
  
                        pswap(i, k);  
                        reverse(j, end);  
                        return true;  
                }  
  
                if (i == begin)  
                {  
                        reverse(begin, end);  
                        return false;  
                }  
        }  
}  
  
int main()
{
	
	arr_string test[6];
	// array of array of strings
	char *mystring[6][4]={{"crossword", "square", "formation", "something"},	// 6
					{"anaesthetist", "thatch", "ethnics", "sabulous"},	// 0
					{"eternal", "texas", "chainsaw", "massacre"},		// 4
					{"africa", "america", "australia", "antarctica"},	// 62
					{"phenomenon", "remuneration", "particularly", "pronunciation"},	// 62
					{"onomatopoeia", "philosophical", "provocatively", "thesaurus"}};	// 20
	int myresult[6]={6,0,4,62,62,20};

	int i,j;
	for(i=0; i<1; i++){
		test[i].size = 4;
		*test[i].arr = malloc(sizeof(char *) * 4);
		for(j=0; j<4; j++){
			test[i].arr[j] = mystring[i][j];
			//printf("*test[%d].arr[%d] = %s\n",i,j,test[i].arr[j]);
		}
       do  
        {  
                for (j = 0; j < 4; j++)  
                {  
                        printf("%s ",test[i].arr[j]);  
                }  
                printf("\n");  
        }  
        while (next_permutation(test[i].arr[0], test[i].arr[3]));
		
		//printf("test[%d] should be %d and is %s\n", i, myresult[i], (next_permutation(test.arr[i]) ? "true":"false"));
	}
	
}
