#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

/*
Given a rectangular matrix containing only digits, calculate the 
number of different 2 × 2 squares in it.

Example

For

matrix = [[1, 2, 1],
          [2, 2, 2],
          [2, 2, 2],
          [1, 2, 3],
          [2, 2, 1]]

the output should be
solution(matrix) = 6.

Here are all 6 different 2 × 2 squares:

    1 2
    2 2
    2 1
    2 2
    2 2
    2 2
    2 2
    1 2
    2 2
    2 3
    2 3
    2 1

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.array.integer matrix

    Guaranteed constraints:
    1 ≤ matrix.length ≤ 100,
    1 ≤ matrix[i].length ≤ 100,
    0 ≤ matrix[i][j] ≤ 9.

    [output] integer

    The number of different 2 × 2 squares in matrix.
*/

void printVector(vector<vector<int>> mat) {
    for (int i=0; i< mat.size()-1; i++){
		for(int j=0; j< mat.size()-1; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
void printSet(set<string> myset) {
/* 	std::copy(
        myset.begin(),
        myset.end(),
        std::ostream_iterator(std::cout, " ")
        ); */
	for (auto it=myset.begin(); it != myset.end(); ++it){ 
		cout << ' ' << *it;
		cout << endl;
	}
}
// this example shows how push_back will not duplicate
// array entries.  quite elegant!!
int solution(std::vector<std::vector<int>> matrix) 
{
    std::set<std::string> res;
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = 0; j < matrix[i].size() - 1; ++j) {
            std::string square;
            square.push_back(matrix[i][j] + '0');
            square.push_back(matrix[i][j + 1] + '0');
            square.push_back(matrix[i + 1][j + 1] + '0');
            square.push_back(matrix[i + 1][j] + '0');
            res.insert(square);
			//cout << square << endl;
        }
		cout << "\n";
		printSet(res);
    }
    return res.size();
}

int main()
{
	vector<vector<int>> test1={{1,2,1}, 
 								{2,2,2}, 
								{2,2,2}, 
								{1,2,3}, 
								{2,2,1}};
								
	vector<vector<int>> test2={{9,9,9,9,9}, 
							 {9,9,9,9,9}, 
							 {9,9,9,9,9}, 
							 {9,9,9,9,9}, 
							 {9,9,9,9,9}, 
							{9,9,9,9,9}};
 
	cout << "test1=" << endl;
	printVector(test1);
	cout << "\nresult=\n" << (solution(test1)) << "\n";
	cout << "test2=" << endl;
	printVector(test2);
	cout << "\nresult=\n" << (solution(test2)) << "\n";
}