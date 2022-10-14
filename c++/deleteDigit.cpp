#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
Given some integer, find the maximal number you 
can obtain by deleting exactly one digit of the 
given number.

Example

    For n = 152, the output should be
    solution(n) = 52;
    For n = 1001, the output should be
    solution(n) = 101.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    10 ≤ n ≤ 106.

    [output] integer
*/

// not so elegant solution with holes
int solution1(int n) {
    vector<int> digits;
    int small=9;
    while(n>0){
        int num=n%10;
        if(num<small)
            small=num;
        n/=10;
        digits.push_back(num);
    }
    //std::reverse(digits.begin(), digits.end());
    for(int i=0; i<digits.size(); i++){
        if(digits[i]==small){
            digits.erase(digits.begin()+i);
			cout<<"i=" << i << " digits.size=" << digits.size() << " " << digits[2] << digits[1] << digits[0] << "\n\n";
            small=0;
			//reverse(digits.begin(), digits.end());
            for (int j=0; j < digits.size(); j++){
                small += (pow(10, j) * digits[j]);
             }
        }
    }
    return small;
}
// very elegant solution using math
int solution(int n) {
	int mymax=0;
	for(int num=1; num<n; num*=10){
		mymax=max(n / 10 / num * num + n % num,mymax);
		cout << "mymax=" << mymax << " num=" << num << " n%num=" << (n%num) << endl;
	}
	return mymax;
}

int main()
{
	int test1=52, test2=74301, test3=222250, test4=218616;
	/*
		152 -> digit / 10 *  1    + digit % 1 -> 15
		    -> digit / 100 * 10   + digit % 10 -> 12
			-> digit / 1000 * 100 + digit % 100 -> 52
	*/
	cout << "test1=" << test1 << " solution=\n" ; cout << solution(test1) << endl;
	cout << "\n\ntest2=" << test2 << " solution=\n"; cout << solution(test2) << endl;
	cout << "\n\ntest3=" << test3 << " solution=\n"; cout << solution(test3) << endl;
	cout << "\n\ntest4=" << test4 << " solution=\n"; cout << solution(test4) << endl;
}