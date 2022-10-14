#include <stdio.h>
#include <stdlib.h>

/*
Consider a sequence of numbers a0, a1, ..., an, in which 
an element is equal to the sum of squared digits of the 
previous element. The sequence ends once an element that 
has already been in the sequence appears again.

Given the first element a0, find the length of the sequence.

Example

    For a0 = 16, the output should be
    solution(a0) = 9.

    Here's how elements of the sequence are constructed:
        a0 = 16
        a1 = 12 + 62 = 37
        a2 = 32 + 72 = 58
        a3 = 52 + 82 = 89
        a4 = 82 + 92 = 145
        a5 = 12 + 42 + 52 = 42
        a6 = 42 + 22 = 20
        a7 = 22 + 02 = 4
        a8 = 42 = 16, which has already occurred before (a0)

    Thus, there are 9 elements in the sequence.

    For a0 = 103, the output should be
    solution(a0) = 4.

    The sequence goes as follows: 103 -> 10 -> 1 -> 1, 4 
	elements altogether.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer a0

    First element of a sequence, positive integer.

    Guaranteed constraints:
    1 ≤ a0 ≤ 105.

    [output] integer
*/


int solution(int a0) {
   int cnt=1, sq1, done=0,result=a0,element=0;
   int last[100]={0};
   last[0]=a0;
    if(a0==1) return cnt+1;
    while(!done){
        sq1=result%10;
        element+=sq1*sq1;
        result=result/10;
		//printf("result=%d,element=%d,last=%d,sq1=%d, cnt=%d\n",result,element,last[cnt],sq1,cnt);
        if(result==0) {
            cnt++;
			for(int j=0; j<cnt; j++){
				if(last[j]==element) return cnt;
			}
			result=element;
			last[cnt]=element;
			element=0;    
        }      
        
    }
    return cnt;
}

int main()
{
	int test[6][2]={{612,16},
					{16,9},
					{103,4},
					{1,2},
					{13,4},
					{89,9}};
	for(int i=0; i<	6; i++)
		printf("test[%d]=%d, should be %d, returns %d\n",i,test[i][0],test[i][1],solution(test[i][0]));

}
