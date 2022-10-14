#include <stdio.h>
#include <stdbool.h>

// find if a number (1<=n<=20) is a power of some number

int main()
{
    int result,n=125;
	if(n==1) return true;
    for(int i=2; i<=20; i++){
        result=i;
        while(result<n){
            if((result*=i)==n) {
				printf("true, i=%d\n",i);
				return true;
			}
			printf("result=%d\n", result);
			if (result==n) break;
        }

    }
    //return false;
}