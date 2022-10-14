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
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 
grid with digits so that each column, each row, and each of the nine 3 × 3 
sub-grids that compose the grid contains all of the digits from 1 to 9.

This algorithm should check if the given grid of numbers represents a 
correct solution to Sudoku.

Example

    For

grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
        [4, 6, 5, 8, 7, 9, 3, 2, 1],
        [7, 9, 8, 2, 1, 3, 6, 5, 4],
        [9, 2, 1, 4, 3, 5, 8, 7, 6],
        [3, 5, 4, 7, 6, 8, 2, 1, 9],
        [6, 8, 7, 1, 9, 2, 5, 4, 3],
        [5, 7, 6, 9, 8, 1, 4, 3, 2],
        [2, 4, 3, 6, 5, 7, 1, 9, 8],
        [8, 1, 9, 3, 2, 4, 7, 6, 5]]

the output should be
solution(grid) = true;

    For

grid = [[8, 3, 6, 5, 3, 6, 7, 2, 9],
        [4, 2, 5, 8, 7, 9, 3, 8, 1],
        [7, 9, 1, 2, 1, 4, 6, 5, 4],
        [9, 2, 1, 4, 3, 5, 8, 7, 6],
        [3, 5, 4, 7, 6, 8, 2, 1, 9],
        [6, 8, 7, 1, 9, 2, 5, 4, 3],
        [5, 7, 6, 9, 8, 1, 4, 3, 2],
        [2, 4, 3, 6, 5, 7, 1, 9, 8],
        [8, 1, 9, 3, 2, 4, 7, 6, 5]]

the output should be
solution(grid) = false.

The output should be false: each of the nine 3 × 3 sub-grids should 
contain all of the digits from 1 to 9.
These examples are represented on the image below.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.array.integer grid

    A matrix representing 9 × 9 grid already filled with numbers from 1 to 9.

    Guaranteed constraints:
    grid.length = 9,
    grid[i].length = 9,
    1 ≤ grid[i][j] ≤ 9.

    [output] boolean

    true if the given grid represents a correct solution to Sudoku, 
	false otherwise.
*/
void printVectorVector(vector<vector<int>> mat) {
    for (int r=0; r< mat.size(); r++){
		for(int c=0; c< mat.size(); c++)
			cout << mat[r][c] << " ";
		cout << endl;
	}
	cout << endl;
}

bool test_true(vector<int> test_sub) {
    for(int x=0; x<test_sub.size(); x++){
        cout << x << "=" << test_sub[x] << " ";
        if(test_sub[x]!=1){
			cout << "false\n\n";
			for(int y=0; y<test_sub.size(); y++)
				test_sub[x]=0;
            return false;
		}
        test_sub[x]=0;
    }
    cout << "true" << endl;
    return true;
}

bool check_outside(vector<vector<int>> grid) {
    vector<int> test_row(9,(0));
    vector<int> test_col(9,(0));
    int x=0,r=0,c=0;   
   for(x=0; x<grid.size(); x++){
		// get row values
		for(r=0; r<grid.size(); r++)
			test_row[grid[r][x]-1]=1;
		cout << "test col " << x << endl;
		if(test_true(test_row)==false)
			return false;
		// get colum values
        for(c=0; c<grid.size(); c++){
            test_col[grid[x][c]-1]=1;
			cout << grid[x][c] << " " ;
		}
		cout << "\ntest row " << x << endl;
        if(test_true(test_col)==false)
            return false;
		for(int y=0; y<test_row.size(); y++){
			test_row[y]=0;
			test_col[y]=0;
		}

   }
    return true;          
}

bool solution(vector<vector<int>> grid) {
    vector<int> test_sub(9,(0));
	// check outer grids
	if(check_outside(grid)==false) return false;
	// check 9 sub grids
    for(int r=0; r<grid.size(); r+=3){
        for(int c=0; c<grid.size(); c+=3){
            for(int sub_r=r; sub_r<r+3; sub_r++){
                for(int sub_c=c; sub_c<c+3; sub_c++){
                    test_sub[grid[sub_r][sub_c]-1]=1;
                    cout << grid[sub_r][sub_c] << " ";
                }
                cout << endl;
            }
			cout << endl;
			if(test_true(test_sub) == false)
				return false;
			cout << endl;
			for(int y=0; y<test_sub.size(); y++)
				test_sub[y]=0;

        }
    }           
     return true;
}


int main()
{
	vector<vector<int>> test1={{8,3,6,5,3,6,7,2,9}, 
								 {4,2,5,8,7,9,3,8,1}, 
								 {7,9,1,2,1,4,6,5,4}, 
								 {9,2,1,4,3,5,8,7,6}, 
								 {3,5,4,7,6,8,2,1,9}, 
								 {6,8,7,1,9,2,5,4,3}, 
								 {5,7,6,9,8,1,4,3,2}, 
								 {2,4,3,6,5,7,1,9,8}, 
								{8,1,9,3,2,4,7,6,5}};
							
	vector<vector<int>> test2={{1,3,2,5,4,6,9,8,7}, 
								 {4,6,5,8,7,9,3,2,1}, 
								 {7,9,8,2,1,3,6,5,4}, 
								 {9,2,1,4,3,5,8,7,6}, 
								 {3,5,4,7,6,8,2,1,9}, 
								 {6,8,7,1,9,2,5,4,3}, 
								 {5,4,6,9,8,1,4,3,2}, 
								 {2,7,3,6,5,7,1,9,8}, 
								{8,1,9,3,2,4,7,6,5}};
	vector<vector<int>> test3={{1,3,2,5,4,6,9,8,7}, 
								 {4,6,5,8,7,9,3,2,1}, 
								 {7,9,8,2,1,3,6,5,4}, 
								 {9,2,1,4,3,5,8,7,6}, 
								 {3,5,4,7,6,8,2,1,9}, 
								 {6,8,7,1,9,2,5,4,3}, 
								 {5,7,6,9,8,1,4,3,2}, 
								 {2,4,3,6,5,7,1,9,8}, 
								 {8,1,9,3,2,4,7,6,5}};
	printVectorVector(test1);
	cout << "test1 should be false and is \n" << (solution(test1) ? "true" : "false") << endl;								
	printVectorVector(test2);
	cout << "test2 should be false and is \n" << (solution(test2) ? "true" : "false") << endl;
	printVectorVector(test3);
	cout << "test3 should be true and is \n" << (solution(test3) ? "true" : "false") << endl;
}
