#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>


using namespace std;


/*
A step(x) operation works like this: it changes a number x into x - s(x), where s(x) 
is the sum of x's digits. You like applying functions to numbers, so given the number n, 
you decide to build a decreasing sequence of numbers: n, step(n), step(step(n)), etc., 
with 0 as the last element.

Building a single sequence isn't enough for you, so you replace all elements of the 
sequence with the sums of their digits (s(x)). Now you're curious as to which number 
appears in the new sequence most often. If there are several answers, return the maximal one.

Example

    For n = 88, the output should be
    solution(n) = 9.
        Here is the first sequence you built: 88, 72, 63, 54, 45, 36, 27, 18, 9, 0;
        And here is s(x) for each of its elements: 16, 9, 9, 9, 9, 9, 9, 9, 9, 0.

    As you can see, the most frequent number in the second sequence is 9.

    For n = 8, the output should be
    solution(n) = 8.
        At first you built the following sequence: 8, 0
        s(x) for each of its elements is: 8, 0

    As you can see, the answer is 8 (it appears as often as 0, but is greater than it).

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    1 ≤ n ≤ 105.

    [output] integer

    The most frequent number in the sequence s(n), s(step(n)), s(step(step(n))), etc.

*/
void print_int_vec(vector<int> a) {
	vector<string> result(a.size());
	for(int i=0; i< a.size(); i++){
		result[i] = to_string(a[i]);
		cout << result[i] << " " ;
	}
	cout << endl;
}

int solution(int n) {
	if(n<10) return n;
    int x=n,j,k,sum=0,count=1, most_freq=0;
    vector<int> result(100000,0);
	result[0]=n;
	// compute step(x)
    while(n) {
        while (x) {
			sum+=x%10;
			x/=10;  
        }
        n-=sum;
		x=n;
		sum=0;
        result[count++]=n; 
		//cout << "result[" << count-1 << "]=" << result[count-1] << endl;
    }
	count--;
    //cout << "total iterations=" << count << endl;

	// compute x-s(x)
    for(j=0; j<count; j++){
        x=result[j];
		sum=0;
		
        while (x) {
            sum+=x%10;
            x/=10;
        }
        result[j]=sum;
		//cout << "result[" << j << "]=" << result[j] << endl;
    }
	// find most frequent digit sum
	sum=0;
	for(j=0; j<count; j++) {
		x=1;
		for(k=j+1; k<count-1; k++)
			if(result[j] == result[k])
				x++;
		if(x>sum){
			sum=x;
			most_freq=result[j];
		}
	}
	if(count==2)
		return (result[0] < result[1]) ? result[1]:result[0];	
	else return most_freq;
}


int main()
{
	int answer=0;
	vector<int> test={17,88,8,1,17,239,994,99999}; 
	
	vector<int> result={9,9,8,1,9,9,9,18};
	
	for(int i=0; i< test.size(); i++){
		answer=solution(test[i]);
		cout << "test#" << i << " should return " << result[i] << " and returns " << answer << endl;
	}
			
}
