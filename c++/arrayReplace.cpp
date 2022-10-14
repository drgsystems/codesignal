#include <iostream>
#include <vector>

using namespace std;

/*
Given an array of integers, replace all the occurrences 
of elemToReplace with substitutionElem.

Example

For inputArray = [1, 2, 1], elemToReplace = 1, and 
substitutionElem = 3, the output should be
solution(inputArray, elemToReplace, substitutionElem) = [3, 2, 3].

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer inputArray

    Guaranteed constraints:
    0 ≤ inputArray.length ≤ 104,
    0 ≤ inputArray[i] ≤ 109.

    [input] integer elemToReplace

    Guaranteed constraints:
    0 ≤ elemToReplace ≤ 109.

    [input] integer substitutionElem

    Guaranteed constraints:
    0 ≤ substitutionElem ≤ 109.

    [output] array.integer
*/
void printVector(vector<int> mat) {
    for (int i=0; i< mat.size(); i++){
        cout << mat[i] << " ";
	}
	cout << endl;
}

vector<int> solution(vector<int> inputArray, int elemToReplace, int substitutionElem) {
	vector<int> replace;
	for(int i=0; i<inputArray.size(); i++)
		replace.push_back(inputArray[i]);
	int cols=replace.size();
		for(int j=0; j<cols; j++){
			if(replace[j]==elemToReplace){
				replace[j]=substitutionElem;
			}
		}
	return replace;
}

int main()
{
		vector<int> test1={1,2,1}; int elemToReplace=1; int substitutionElem=3;
		printVector(test1);
		vector<int> result1=solution(test1, elemToReplace, substitutionElem);
		printVector(result1);
		
}