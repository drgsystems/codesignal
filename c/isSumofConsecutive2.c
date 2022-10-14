

/*
Find the number of ways to express n as sum of some (at least two) 
consecutive positive integers.

Example

    For n = 9, the output should be
    solution(n) = 2.

    There are two ways to represent n = 9: 2 + 3 + 4 = 9 and 4 + 5 = 9.

    For n = 8, the output should be
    solution(n) = 0.

    There are no ways to represent n = 8.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer n

    A positive integer.

    Guaranteed constraints:
    1 ≤ n ≤ 104.

    [output] integer
*/
for 9 expect 2
for 8 expect 0
for 15 expect 3
for 24 expect 1
for 13 expect 1
for 25 expect 2
for 99 expect 5
/*

*/

int solution(int n) {
	int cnt=0,test=0,i,j=1;
	if(n<2) return 0;
	if(n/2+n/2+1==n) cnt++;
	
	while(j<n){
		test=n/2-j+1;
		for(i=n/2-j; test<n && i>0; i--){
            test+=i;
            printf("n=%d test=%d, i=%d, cnt=%d\n",n, test,i,cnt);
			if(test==n){ cnt++; break;}
		}
		j++;
	}
	return cnt;
		
}

int main()
{


}
