#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>


using namespace std;


/*
Let's call two integers A and B friends if each integer from the array divisors 
is either a divisor of both A and B or neither A nor B. If two integers are friends, 
they are said to be in the same clan. How many clans are the integers from 1 to k, 
inclusive, broken into?

Example

For divisors = [2, 3] and k = 6, the output should be
solution(divisors, k) = 4.

The numbers 1 and 5 are friends and form a clan, 2 and 4 are friends and form a clan, 
and 3 and 6 do not have friends and each is a clan by itself. So the numbers 1 through 
6 are broken into 4 clans.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer divisors

    A non-empty array of positive integers.

    Guaranteed constraints:
    2 ≤ divisors.length < 10,
    1 ≤ divisors[i] ≤ 10.

    [input] integer k

    A positive integer.

    Guaranteed constraints:
    5 ≤ k ≤ 10.

    [output] integer


*/
void print_int_vec(vector<int> a) {
	vector<string> result(a.size());
	for(int i=0; i< a.size(); i++){
		result[i] = to_string(a[i]);
		cout << result[i] << " " ;
	}
	cout << endl;
}

int solution(vector<int> divisors, int k) {
  //var clans = Array(1024).fill(0);
  vector<int> clans(1024,0);
  //var c = 0;
  int c = 0;
  for (int i = 1; i <= k; i++) {
    c = 0;
    for (int j = 0; j < divisors.size(); j++) {
      if (i % divisors[j] == 0) {
        c = c | (1 << j);
		
      }
    }
	//cout << c << endl;   //c | (1 << j) << "(1 << j) =" << (1 << j) << "j=" << j << endl;
    clans[c] = 1;
  }
  return accumulate(clans.begin(), clans.end(), 0);  //clans.reduce((a, b) => a + b);
}

int main()
{
	
	vector<vector<int>> test={{2,3},{2, 3, 4},{1, 3},{6, 2, 2, 8, 9, 2, 2, 2, 2},{2, 5},{1, 2, 3},{5, 6},{7, 1, 3, 4, 4}};		
	vector<int> k={6,6,10,10,9,8,5,5};
	vector<int> result={4,5,2,5,3,4,2,3};
	

	for(int i=0; i<result.size(); i++)
		cout << "test# " <<  i <<  " should return " <<  result[i] <<  " and result is " << solution(test[i],k[i]) << endl;
			
}
