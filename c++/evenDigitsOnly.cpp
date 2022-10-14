#include <iostream>

using namespace std;

/*
Check if all digits of the given integer are even.

Example

    For n = 248622, the output should be
    solution(n) = true;
    For n = 642386, the output should be
    solution(n) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Guaranteed constraints:
    1 ≤ n ≤ 109.

    [output] boolean

    true if all digits of n are even, false otherwise.
*/

bool solution(int n) {
	while(n!=0){
		int r=n%10;
		if(r%2>0) return false;
		n=n/10;
	}
	return true;
}

int main()
{
	int test1=248622;
	int test2=642386;
	
	cout << "test1 result=" << (solution(test1) ? "True" : "False") << endl;
	cout << "test2 result=" << (solution(test2) ? "True" : "False") << endl;	
}