#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
	Given a position of a knight on the standard chessboard, 
	find the number of different moves the knight can perform.

	The knight can move to a square that is two squares horizontally 
	and one square vertically, or two squares vertically and one 
	square horizontally away from it. The complete move therefore 
	looks like the letter L. Check out the image below to see all 
	valid moves for a knight piece that is placed on one of the 
	central squares.

Example

    For cell = "a1", the output should be
    solution(cell) = 2.
	
	For cell = "c2", the output should be
	solution(cell) = 6.
	
Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string cell

    String consisting of 2 letters - coordinates of the knight 
	on an 8 × 8 chessboard in chess notation.

    Guaranteed constraints:
    cell.length = 2,
    'a' ≤ cell[0] ≤ 'h',
    1 ≤ cell[1] ≤ 8.

    [output] integer

*/

int solution(string cell) {
    int col=cell[0]-'a'+1;
    int row=cell[1]-'1'+1;
    int count=0;
    if(col+2<9){
        if(row+1<9)
            count++;
        if(row-1>=1)
            count++;
    }
    if(col-2>=1){
        if(row+1<9)
            count++;
        if(row-1>=1)
            count++;   
    }
    if(row+2<9){
        if(col+1<9)
            count++;
        if(col-1>=1)
            count++;
    }
    if(row-2>=1){
        if(col+1<9)
            count++;
        if(col-1>=1)
            count++;
    }
    return count;
}

int main()
{
	string test1={"a7"};
	string test2={"b7"};
	string test3={"c7"};
	string test4={"d7"};
	string test5={"e7"};
	string test6={"f7"};
	string test7={"g7"};
	string test8={"h7"};
	
	cout << test1 << " " << solution(test1) << endl;
	cout << test2 << " " << solution(test2) << endl;
	cout << test3 << " " << solution(test3) << endl;
	cout << test4 << " " << solution(test4) << endl;
	cout << test5 << " " << solution(test5) << endl;
	cout << test6 << " " << solution(test6) << endl;
	cout << test7 << " " << solution(test7) << endl;
	cout << test8 << " " << solution(test8) << endl;
}