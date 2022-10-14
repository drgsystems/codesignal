#include <stdio.h>
#include <stdlib.h>

/*
Ratiorg got statues of different sizes as a present from CodeMaster 
for his birthday, each statue having an non-negative integer size. 
Since he likes to make things perfect, he wants to arrange them from 
smallest to largest so that each statue will be bigger than the previous 
one exactly by 1. He may need some additional statues to be able to 
accomplish that. Help him figure out the minimum number of additional 
statues needed.

Example

For statues = [6, 2, 3, 8], the output should be
solution(statues) = 3.

Ratiorg needs statues of sizes 4, 5 and 7.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] array.integer statues

    An array of distinct non-negative integers.

    Guaranteed constraints:
    1 ≤ statues.length ≤ 10,
    0 ≤ statues[i] ≤ 20.

    [output] integer

    The minimal number of statues that need to be added to existing 
	statues such that it contains every integer size from an interval [L, R] 
	(for some L, R) and no other sizes.
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
/*
statues: [6, 2, 3, 8]
statues: [0, 3]
statues: [5, 4, 6]
statues: [6, 3]
statues: [1]

*/
typedef struct arr_integer {
  int size;
  int *arr;
} arr_integer;

int solution(arr_integer statues) {
	int smallest=20,largest=0,result=0;
	for(int i=0; i<statues.size; i++){
		if(statues.arr[i]<=smallest)
			smallest=statues.arr[i];
		if(statues.arr[i]>largest)
			largest=statues.arr[i];
    }
    printf("smallest=%d, largest=%d\n",smallest,largest);
    return largest-smallest-statues.size+1;
}

int main()
{

	arr_integer arr; 
	arr.size=sizeof(test)/sizeof(int);
	arr.arr=malloc(sizeof(int) * arr.size);
	
}
