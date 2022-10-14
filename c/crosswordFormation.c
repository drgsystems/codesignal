#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
// this program has problems but the .cpp version of this works with iter_swap!!!
/*
You're a crossword fanatic, and have finally decided to try and create your own. However, you also love symmetry and good design, so you come up with a set of rules they should follow:

    the crossword must contain exactly four words;
    these four words should form four pairwise intersections;
    all words must be written either left-to-right or top-to-bottom;
    the area of the rectangle formed by empty cells inside the intersections isn't equal to zero.

Given 4 words, find the number of ways to make a crossword following the above-described rules. Note that two crosswords which differ by rotation are considered different.

Example

For words = ["crossword", "square", "formation", "something"], the output should be
solution(words) = 6.

The six crosswords can be formed as shown below:

  f                         f                             f
  o                     c r o s s w o r d     c r o s s w o r d
c r o s s w o r d           r   o                   q     r
  m   q                     m   m                   u     m
  a   u            ;  s q u a r e          ;        a     a
  t   a                     t   t                   r     t
  i   r                     i   h             s o m e t h i n g
s o m e t h i n g           o   i                         o
  n                         n   n                         n
                                g                               
                                                              
    c         s               s                                      
f o r m a t i o n       c     q               c         s          
    o         m         r     u               r         o      
    s q u a r e       f o r m a t i o n       o         m            
    s         t    ;    s     r            ;  s q u a r e                  
    w         h         s o m e t h i n g     s         t         
    o         i         w                     w         h     
    r         n         o                   f o r m a t i o n            
    d         g         r                     r         n         
                        d                     d         g             

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.string words

    An array of distinct strings, the words you need to use in your crossword.

    Guaranteed constraints:
    words.length = 4,
    3 ≤ words[i].length < 15.

    [output] integer

    The number of ways to make a correct crossword of the desired formation.
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

typedef struct arr_string {
	int size;
	char *arr[4];
} arr_string;

int compare_function(const void *a,const void *b) {
return (strcmp((char *)a,(char *)b));
}

int process(char** w) {
    int ans = 0;
    for (int i = 0; i < strlen(w[0]); i++)
		for (int j = 0; j < strlen(w[1]); j++) {
			if (w[0][i] == w[1][j]) {
				for (int k = j+2; k < strlen(w[1]); k++)
				for (int h = 0; h < strlen(w[2]); h++) {
					if (w[1][k] == w[2][h]) {
						for (int x = h+2; x < strlen(w[2]); x++)
						for (int y = 0; y < strlen(w[3]); y++) {
							if (w[2][x] == w[3][y]) {
								int width = k - j;
								int height = x - h;
								if (y - width >= 0 && i + height < strlen(w[0])) {
									if (w[3][y - width] == w[0][i + height])
										ans++;
								}
							}
						}
					}
				}
			}
		}
    return ans;
}


int solution(arr_string words) {
	printf("%s, %s, %s, %s\n",words.arr[0], words.arr[1], words.arr[1], words.arr[2]);
    qsort(words.arr, sizeof(words.arr)/sizeof(*words.arr), sizeof(*words.arr), compare_function);
    
    int cnt = 0, next_perm=20;
    do {
        cnt += process(words.arr);
		next_perm--;
		//next_permutation(words.arr.begin(), words.arr.end());
    } while (next_perm);
    
    return cnt;
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

 
	for(int i=0; i<6; i++){
		test[i].size = 4;
		*test[i].arr = malloc(sizeof(char *) * 4);
		for(int j=0; j<4; j++){
			test[i].arr[j] = mystring[i][j];
			//printf("*test[%d].arr[%d] = %s\n",i,j,test[i].arr[j]);
		}

		printf("test[%d] should be %d and is %d\n", i, myresult[i], solution(test[i]));
	}
	
}
