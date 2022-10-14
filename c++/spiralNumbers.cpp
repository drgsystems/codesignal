#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;
using std::to_string;

/*
Construct a square matrix with a size N × N containing integers 
from 1 to N * N in a spiral order, starting from top-left and in 
clockwise direction.

Example

For n = 3, the output should be

solution(n) = [[1, 2, 3],
                    [8, 9, 4],
                    [7, 6, 5]]

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer n

    Matrix size, a positive integer.

    Guaranteed constraints:
    3 ≤ n ≤ 100.

    [output] array.array.integer
*/
void printVectorVector(vector<vector<int>> mat) {
    for (int r=0; r< mat.size(); r++){
		for(int c=0; c< mat.size(); c++)
			cout << mat[r][c] << " ";
		cout << endl;
	}
	cout << endl;
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> result(n,vector<int>(n,0));
    int loc=1,ref_col0=4*(n-1);
    //int loc=1, i,j,k,l,m;
	int i,r,c,l,m;
    for(i=0; i<n/2; i++){
		
        for(c=i; c<n-i; c++)
            result[i][c]=loc++;
        for(r=i+1; r<n-i; r++)
            result[r][n-i-1]=loc++;
        for(c=n-i-2; c>=i; c--)
            result[n-i-1][c]=loc++;
        for(r=n-i-2; r>=i+1; r--)
                result[r][i]=loc++;
		cout << "i=" << i << endl;
		//printVectorVector(result);
    }
	if(n%2);
		result[n/2][n/2]=(n*n);
	printVectorVector(result);
     return result; 
}

int main()
{
	vector<vector<int>> result;
	cout << "matrix=10 result= " << endl;
	result=solution(10);
	
	cout << "matrix=7 result= " << endl;
	result=solution(7);
	
}