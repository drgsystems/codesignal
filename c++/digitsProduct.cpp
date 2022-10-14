#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;
/*
Given an integer product, find the smallest positive 
(i.e. greater than 0) integer the product of whose digits 
is equal to product. If there is no such integer, return -1 
instead.

Example

    For product = 12, the output should be
    solution(product) = 26;
    For product = 19, the output should be
    solution(product) = -1.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer product

    Guaranteed constraints:
    0 ≤ product ≤ 600.

    [output] integer
*/

int solution(int product) {
	if(product==0) return 10;
	else if(product<10) return product;
	
	int smallPos=0;
	while(product >9){
		int orig = product;
		for(int f=9; f>1; f--){
			if(product % f == 0){
				int nextDigit = product / f;
				nextDigit = digitsProduct(nextDigit);
				if(nextDigit== -1) return -1;
				smallPos = smallPos * 10 + nextDigit;
				product=f;
				break;
			}
		}
		if(product == orig) return -1;
	}
	return smallPos * 10 + product;
}

int solution(int product) {
    int i=9,j=0,result;
    while(product%i!=0){
        i--;
    }
    j=product/i;
    i=9;
    result=i;
    while(j%i){
        i--
    }
    result+=i*10;
    if()
        
}

int main()
{

	vector<int> test1=(9,{12,19,450,0,13,1,243,576,360}); // output=26,-1,2559,10,-1,1,399,889,589
			