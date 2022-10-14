#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* #include <vector>  
#include <iostream>  
#include <algorithm> 
#include <string> 
  
using namespace std; */  
  
//template<typename It>  

void pswap(char* l[], char* r[]) {
    char** temp = l;
    l = r;
    r = temp;
}

/* void reverse(char* A[], int l, int r) {
     int size = (r-l+1);
    for (int i = 0; i < size/2; ++i)
        pswap(A[l+i], A[r-i]); 
	while (l < r) {
        pswap(&A[l++], &A[r--]);
    }
} */

void reverse(char* A[], char* B[]) {
	int l=0, r=4;
	while (l < r) {
        pswap(&A[l++], &B[r--]);
    }
}

bool my_next_permutation(char* begin, char* end)  
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
  
                        //iter_swap(i, k);
						pswap(&i, &k);
                        reverse(&j, &end);  
                        return true;  
                }  
  
                if (i == begin)  
                {  
                        reverse(&begin, &end);  
                        return false;  
                }  
        }  
}  
  
int main()  
{  
        //vector<int> v = { 1, 2, 3, 4 };
		char* mystring[4]={"crossword", "square", "formation", "something"};
  
        do  
        {  
                for (int i = 0; i < 4; i++)  
                {  
                        //cout << mystring[i] << " ";
						printf("%s ",mystring[i]);
                }  
                //cout << endl;
				printf("\n");				
        }  
        while (my_next_permutation(mystring[0], mystring[3]));  
} 