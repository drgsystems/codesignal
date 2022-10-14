#include <iostream>
using namespace std;

/*
You have deposited a specific amount of money into your bank account. 
Each year your balance increases at the same growth rate. With the 
assumption that you don't make any additional deposits, find out how 
long it would take for your balance to pass a specific threshold.

Example

For deposit = 100, rate = 20, and threshold = 170, the output should be
solution(deposit, rate, threshold) = 3.

Each year the amount of money in your account increases by 20%. So 
throughout the years, your balance would be:

    year 0: 100;
    year 1: 120;
    year 2: 144;
    year 3: 172.8.

Thus, it will take 3 years for your balance to pass the threshold, so the answer is 3.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer deposit

    The initial deposit, guaranteed to be a positive integer.

    Guaranteed constraints:
    1 ≤ deposit ≤ 100.

    [input] integer rate

    The rate of increase. Each year the balance increases by the rate percent of the current sum.

    Guaranteed constraints:
    1 ≤ rate ≤ 100.
*/

int solution(int deposit, int rate, int threshold) {
    int i=0;
	float d=deposit;
    while(d<threshold){
		i++;
		d+=(d * rate)/100;
	}
    return i;
}
	
int main()
{
	int dep=100, interest=40, max=170;
	cout << "interest=" << interest << ", number of years to pass " << max << "=" << (solution(dep,interest,max)) << endl;
}