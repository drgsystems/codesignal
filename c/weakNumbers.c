#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
We define the weakness of number x as the number of positive integers 
smaller than x that have more divisors than x.

It follows that the weaker the number, the greater overall weakness it has. 
For the given integer n, you need to answer two questions:

    what is the weakness of the weakest numbers in the range [1, n]?
    how many numbers in the range [1, n] have this weakness?

Return the answer as an array of two elements, where the first element 
is the answer to the first question, and the second element is the answer 
to the second question.

Example

For n = 9, the output should be
solution(n) = [2, 2].

Here are the number of divisors and the specific weakness of 
each number in range [1, 9]:

    1: d(1) = 1, weakness(1) = 0;
    2: d(2) = 2, weakness(2) = 0;
    3: d(3) = 2, weakness(3) = 0;
    4: d(4) = 3, weakness(4) = 0;
    5: d(5) = 2, weakness(5) = 1;
    6: d(6) = 4, weakness(6) = 0;
    7: d(7) = 2, weakness(7) = 2;
    8: d(8) = 4, weakness(8) = 0;
    9: d(9) = 3, weakness(9) = 2.

As you can see, the maximal weakness is 2, and there are 2 
numbers with that weakness level.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer n

    Guaranteed constraints:
    1 ≤ n ≤ 1000.

    [output] array.integer

    Array of two elements: the weakness of the weakest number, 
	and the number of integers in range [1, n] with this weakness.
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

typedef struct arr_integer {
	int size;
	int *arr;
} arr_integer;

int ndivisors(int x) {
    int ret = 0;
    for (int i = 1; i <= x; i++) {
      if (x % i == 0)
        ret++;
    }
    return ret;
}

arr_integer solution(int n) {

	//int d = Array(n).fill(0);
	arr_integer result;
	result.arr=malloc(sizeof(int) * 2);
	
	int d[n];
	int w = 0;
	int wc = 0;
	int t = 0;
  
	for (int i = 1; i <= n; i++) {
		t = 0;
		d[i - 1] = ndivisors(i);
		for (int j = 1; j < i; j++) {
			if (d[j - 1] > d[i - 1])
			t++;
		}

		if (t == w) {
			wc++;
		} 
		else if (t > w) {
			w = t;
			wc = 1;
		}
	}
	result.arr[0]=w;
	result.arr[1]=wc;
	result.size=2;
	printf("result.size=%d,result.arr[0]=%d,result.arr[1]=%d\n",result.size,result.arr[0],result.arr[1]);
	return result;

}

int main()
{
	arr_integer test[4];
	
	int array[4][3]={{9,2,2}, {1,0,1}, {2,0,2}, {7,2,1}};
		
	for(int i =0; i<4; i++){
		test[i].arr=malloc(sizeof(int) * 2);
		test[i]=solution(array[i][0]);
		printf("test[%d], num=%d, expected out=[%d,%d]\n",i,test[i].size,test[i].arr[0],test[i].arr[1]);
	}
}
