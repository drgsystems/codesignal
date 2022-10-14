#include <iostream>

using namespace std;

/*
Correct variable names consist only of English letters, 
digits and underscores and they can't start with a digit.

Check if the given string is a correct variable name.

Example

    For name = "var_1__Int", the output should be
    solution(name) = true;
    For name = "qq-q", the output should be
    solution(name) = false;
    For name = "2w2", the output should be
    solution(name) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string name

    Guaranteed constraints:
    1 ≤ name.length ≤ 10.

    [output] boolean

    true if name is a correct variable name, false otherwise.
*/
bool solution(string name) {
	if(name[0]!='_' && !(isalpha(name[0]))) return false;
	for(int i=0; i< name.length(); i++){
		if(!(isdigit(name[i])) && !(name[i]=='_') && !(isalpha(name[i])))
				return false;
	}
	return true;
}

int main()
{
	string test1={"var_1__Int"};
	string test2={"qq-q"};
	string test3={"2w2"};
	
	cout << "test1=" << test1 << " result=" << (solution(test1) ? "True" : "False") << endl;
	cout << "test2=" << test1 << " result=" << (solution(test2) ? "True" : "False") << endl;
	cout << "test3=" << test1 << " result=" << (solution(test3) ? "True" : "False") << endl;
}