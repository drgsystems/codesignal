#include <iostream>

using namespace std;

/*
Given two cells on the standard chess board, determine whether 
they have the same color or not.

Example

    For cell1 = "A1" and cell2 = "C3", the output should be
    solution(cell1, cell2) = true.

    For cell1 = "A1" and cell2 = "H3", the output should be
    solution(cell1, cell2) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string cell1

    Guaranteed constraints:
    cell1.length = 2,
    'A' ≤ cell1[0] ≤ 'H',
    1 ≤ cell1[1] ≤ 8.

    [input] string cell2

    Guaranteed constraints:
    cell2.length = 2,
    'A' ≤ cell2[0] ≤ 'H',
    1 ≤ cell2[1] ≤ 8.

    [output] boolean

    true if both cells have the same color, false otherwise.
*/

bool solution(string cell1, string cell2) {

	if((cell1[0] % 2 + cell1[1] % 2)%2 == (cell2[0] % 2 + cell2[1] % 2)%2)
		return true;
	else return false;
}

int main()
{
	string test1={"A1"}, test2={"H3"}, test3={"C3"}, test4={"B2"}, test5={"D4"};
	
	cout << "A1 - H3 =" << (solution(test1,test2) ? "True" : "False") << endl;
	cout << "A1 - C3 =" << (solution(test1,test3) ? "True" : "False") << endl;
	cout << "A1 - B2 =" << (solution(test1,test4) ? "True" : "False") << endl;
	cout << "A1 - D4 =" << (solution(test1,test5) ? "True" : "False") << endl;
	cout << "H3 - D4 =" << (solution(test2,test5) ? "True" : "False") << endl;
}