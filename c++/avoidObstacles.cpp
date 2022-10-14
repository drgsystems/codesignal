#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an array of integers representing coordinates 
of obstacles situated on a straight line.

Assume that you are jumping from the point with coordinate 0 
to the right. You are allowed only to make jumps of the same 
length represented by some integer.

Find the minimal length of the jump enough to avoid all the 
obstacles.

Example

For inputArray = [5, 3, 6, 7, 9], the output should be
solution(inputArray) = 4.

Check out the image below for better understanding:

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer inputArray

    Non-empty array of positive integers.

    Guaranteed constraints:
    2 ≤ inputArray.length ≤ 1000,
    1 ≤ inputArray[i] ≤ 1000.

    [output] integer

    The desired length.
*/

void print_array(vector<int> inputArray){
	for(int i=0; i< inputArray.size(); i++)
		cout << inputArray[i] << " ";
}

int solution(vector<int> inputArray) {
	cout << "array before sort=";
	print_array(inputArray);
	cout << endl;
	sort(inputArray.begin(), inputArray.end());
	cout << "array after sort=";
	print_array(inputArray);
	cout << endl;

	int jump = 1,temp=0;
	while(temp <= inputArray.back()){
		cout << " temp=" << temp << " jump=" << jump << endl;
		if(std::find(inputArray.begin(),inputArray.end(),temp)!=inputArray.end()){
			temp=0;
			jump++;
			cout << "!=inputArray.end " << jump << endl;
		}else{
			temp+=jump;
			cout << "==inputArray.end " << jump << endl;
		}
	}
	return jump;
}

int main()
{
	vector<int> test1={1, 4, 10, 6, 2};
	vector<int> test2={5, 3, 6, 7, 9};
	cout << "result = " << solution(test1) << endl;
	cout << "result = " << solution(test2) << endl;
}