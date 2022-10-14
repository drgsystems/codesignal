#include <iostream>

using namespace std;

/*
Given a string, your task is to replace each of its characters by the next one 
in the English alphabet; i.e. replace a with b, replace b with c, etc (z would 
be replaced by a).

Example

For inputString = "crazy", the output should be solution(inputString) = "dsbaz".

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string inputString

    A non-empty string consisting of lowercase English characters.

    Guaranteed constraints:
    1 ≤ inputString.length ≤ 1000.

    [output] string

    The resulting string after replacing each of its characters.
*/

string solution(string inputString) {
	string result;
	for(int c=0; c<inputString.length(); c++)
		result.push_back(inputString[c]);
	
	for(int i=0; i<result.length(); i++)
		if(result[i]=='z')
			result[i]='a';
		else
			result[i]=result[i]+1;
	return result;
}

int main()
{
	string test1={"crazy"};
	cout << "test1=" << test1 << " result=" << solution(test1) << endl;
}
