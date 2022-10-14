#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 4
char* A[4];
#define RAND_MOD 4

void pswap(char *l[], char *r[]) {
    char** temp = l;
    l = r;
    r = temp;
}

void reverse(char* A[], int l, int r) {
 /*    int size = (r-l+1);
    for (int i = 0; i < size/2; ++i)
        pswap(A[l+i], A[r-i]); */
	while (l < r) {
        pswap(&A[l++], &A[r--]);
    }
}
int find_decreasing_interval(char* A[], int l, int r) {
	int j=0;
	  while (r > l) {
      if (A[l] < A[r]) {
          break;
      }
      --j;
  }
  return j;
}
  
bool next_different_permutation(char* A[], int l, int r) {
    if (r-l+1 <= 1)
		// return false when [l,r] is(or back to) an increasing interval.
        return false;

  int j = find_decreasing_interval(A, l, r); 
  // j will point to the highest peak of the interval [i,r].
  // this loop will find the first increasing [i,j] from r to l.


  if (j > l) {
      int k = r;
      // find the first A[k] where A[k] > A[j-1].
      while (!(A[j-1] < A[k])) {
          --k;
      }
      pswap(&A[j-1], &A[k]);
 }

  reverse(A, j, r);
  return j > l;
}

//Usage:



void next_different_permutation_test_distinct() {
    //for (int i = 0; i < ARRAY_SIZE; ++i)
    //    A[i] = i+1;
    do {
		printf("%s %s %s %s\n",A[0],A[1],A[2],A[3]);
        //print_array(A, ARRAY_SIZE, PRINT_WIDTH);
    } while (next_different_permutation(A, 0, ARRAY_SIZE-1));
    // the order will back to A[l]<A[l+1]<...<A[r]
}

void next_different_permutation_test_some_identical() {
    for (int i = 0; i < ARRAY_SIZE; ++i)
        A[i] = A[rand()%RAND_MOD];
    do {
		printf("%s %s %s %s\n",A[0],A[1],A[2],A[3]);
        //print_array(A, ARRAY_SIZE, PRINT_WIDTH);
    } while (next_different_permutation(A, 0, ARRAY_SIZE-1));
}

int main()
{
	char* test[4]={"crossword", "square", "formation", "something"};
	for(int i=0; i<4; i++){
		A[i]=malloc(sizeof(char) *100);
		A[i]=test[i];
	}
		
	next_different_permutation_test_distinct();
}
	
