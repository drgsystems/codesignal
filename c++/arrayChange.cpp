#include <iostream>
#include <vector>

using namespace std;
/* 
You are given an array of integers. On each move you are allowed to increase exactly one 
of its element by one. Find the minimal number of moves required to obtain a strictly 
increasing sequence from the input.

Example

For inputArray = [1, 1, 1], the output should be
solution(inputArray) = 3.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer inputArray

    Guaranteed constraints:
    3 ≤ inputArray.length ≤ 105,
    -105 ≤ inputArray[i] ≤ 105.

    [output] integer

    The minimal number of moves needed to obtain a strictly increasing sequence from inputArray.
    It's guaranteed that for the given test cases the answer always fits signed 32-bit integer type.
 */

int solution(vector<int> inputArray) {
int answer = 0;

	for (int i = 1; i < inputArray.size(); i++) {
		if(inputArray[i] <= inputArray[i-1]) {
			answer += inputArray[i-1] - inputArray[i] + 1;
			inputArray[i] += inputArray[i-1] - inputArray[i] + 1;
		}
	}
	
	return answer;
}

int main() {

	vector<int> inputArray1 = {1, 1, 1}; int ans1= 3;
	vector<int> inputArray2 = {-1000, 0, -2, 0}; int ans2= 5;
	vector<int> inputArray3 = {2, 1, 10, 1}; int ans3= 12;
	vector<int> inputArray4 = {2, 3, 3, 5, 5, 5, 4, 12, 12, 10, 15}; int ans4= 13;
	vector<int> inputArray5 = {3122, -645, 2616, 13213, -8069}; int ans5= 25559;
	vector<int> inputArray6 = {9796, 1283, -2825, 3870, -6727, -8616, -10191, 
					-7727, 7074, 1580, -4583, 162, 2980, -3861, 
					9452, 8145, 1222, -1125, 5142, -5657, -974, 
					-986, -9627, 5244, 8866, 3336, -9946, -5271, 
					10582, 3013, 8030, 4471, -3420, 9496, -3533, 
					-8030, 10007, 2549, -8195, 7119, 302, -5322, 
					-3537, 209, -8134, -9176, 6336, -1771, 9851, 
					3644, 9629, -2603, 3988, 10579, 2221, 1101, 
					1465, 5002, -6203, -8864, 596, 6005, 4554, 8526, 
					2178, -5447, -232, -9734, 7402, -3984, -7161, 
					-2139, -3181, 10445, 4535, 6926, 7156}; int ans6= 737073;


	cout << "inputArray1 answer should be = " << ans1 << " returns " << solution(inputArray1) << "\n";
	cout << "inputArray2 answer should be = " << ans2 << " returns " << solution(inputArray2) << "\n";
	cout << "inputArray6 answer should be = " << ans6 << " returns " << solution(inputArray6) << "\n";
	
}