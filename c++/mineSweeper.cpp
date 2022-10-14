#include <iostream>
#include <vector>

using namespace std;

/* 
In the popular Minesweeper game you have a board with some 
mines and those cells that don't contain a mine have a number 
in it that indicates the total number of mines in the neighboring 
cells. Starting off with some arrangement of mines we want to 
create a Minesweeper game setup.

Example

For

matrix = [[true, false, false],
          [false, true, false],
          [false, false, false]]

the output should be

solution(matrix) = [[1, 2, 1],
                       [2, 1, 1],
                       [1, 1, 1]]

Check out the image below for better understanding:

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.array.boolean matrix

    A non-empty rectangular matrix consisting of boolean values - 
	true if the corresponding cell contains a mine, false otherwise.

    Guaranteed constraints:
    2 ≤ matrix.length ≤ 100,
    2 ≤ matrix[0].length ≤ 100.

    [output] array.array.integer

    Rectangular matrix of the same size as matrix each cell of 
	which contains an integer equal to the number of mines in the 
	neighboring cells. Two cells are called neighboring if they 
	share at least one corner.

*/
void printVector(vector<vector<int>> const &mat) {
    for (vector<int> row: mat)
    {
        for (int val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

;
void printBoolVect(vector<vector<bool>> &dp){
	for (vector<bool> row: dp)
	{
		for (bool val: row) {
			cout << val << " ";
		}
		cout << endl;
	}
 /*    for(auto &x :dp){
        for(bool y:x){
            cout<<y<<' ';
        }
        cout<<endl;
    } */
}

int check(vector<vector<bool>> mat, int rw, int cl) {
	int mines = 0;
	// check if rw/cl inside matrix
	int u = rw - 1 >= 0? rw -1 : 0;
	int d = rw + 1 <= mat.size() -1 ? rw + 1 : mat.size() -1;
	int l = cl -1 >= 0 ? cl -1 : 0;
	int r = cl + 1 <= mat[0].size() -1 ? cl + 1 : mat[0].size() -1;
	// go around position and add weight
	for( int i = u; i <= d; i++) {
		for(int j =l; j <= r; j++) {
			if(mat[i][j] && (!(rw == i && cl == j))) {
				mines++;
			}
		}
	}
	return mines;
}

vector<vector<int>> solution(vector<vector<bool>> matrix) {
	int rws = matrix.size();
	int cls = matrix[0].size();
	vector<vector<int>> mines(rws, vector<int>(cls,0));
	// go around each position and check its surroundings
	for(int r=0; r<rws; r++){
		for(int c=0; c<cls; c++){
			mines[r][c]=check(matrix,r,c);
		}
	}
	return mines;
}

/* vector<vector<int>> solution(vector<vector<bool>> matrix) {

	int row_size=matrix.size();
	int col_size=matrix[0].size();
	
	vector<vector<int>> result(row_size,vector<int>(col_size,0));
	
} */

int main()
{
	vector<vector<bool>> test1={		// [[0,0,0], [0,0,0]]
		{false,false,false}, 
		{false,false,false}};
		 
	vector<vector<bool>> test2={		//[[1,2,1], [2,1,1], [1,1,1]]
		{true,false,false}, 
         {false,true,false}, 
		{false,false,false}};

	vector<vector<bool>> test3={		//[[3,5,3], [5,8,5], [3,5,3]]
		{true,true,true}, 
		{true,true,true}, 
		{true,true,true}};

	vector<vector<bool>> test4={		//[[0,2,2,1], [3,4,3,3], [1,2,3,1]]
		{true,false,false,true}, 
		{false,false,true,false}, 
		{true,true,false,true}};

	vector<vector<int>> result1(test1.size());

	cout << "array to blur = \n"; printBoolVect(test1);
	cout << "array size test1=" << test2.size() << endl;
	result1=solution(test1);
	cout << "array after blur = \n"; printVector(result1);
	
	vector<vector<int>> result2(test2.size());

	cout << "array to blur = \n";printBoolVect(test2);
	cout << "array size test2=" << test2.size() << endl;
	result2=solution(test2);
	cout << "array after blur = \n"; printVector(result2);
	
	vector<vector<int>> result3(test3.size());

	cout << "array to blur = \n"; printBoolVect(test3);
	cout << "array size test3=" << test3.size() << endl;
	result3=solution(test3);
	cout << "array after blur = \n"; printVector(result3);
	
	vector<vector<int>> result4(test4.size());

	cout << "array to blur = \n"; printBoolVect(test4);
	cout << "array size test4=" << test4.size() << endl;
	result4=solution(test4);
	cout << "array after blur = \n"; printVector(result4);

}