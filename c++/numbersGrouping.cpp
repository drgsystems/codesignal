#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;


/*
You are given an array of integers that you want distribute between several 
groups. The first group should contain numbers from 1 to 104, the second should 
contain those from 104 + 1 to 2 * 104, ..., the 100th one should contain numbers 
from 99 * 104 + 1 to 106 and so on.

All the numbers will then be written down in groups to the text file in such a way that:

    the groups go one after another;
    each non-empty group has a header which occupies one line;
    each number in a group occupies one line.

Calculate how many lines the resulting text file will have.

Example

For a = [20000, 239, 10001, 999999, 10000, 20566, 29999], the output should be
solution(a) = 11.

The numbers can be divided into 4 groups:

    239 and 10000 go to the 1st group (1 ... 104);
    10001 and 20000 go to the second 2nd (104 + 1 ... 2 * 104);
    20566 and 29999 go to the 3rd group (2 * 104 + 1 ... 3 * 104);
    groups from 4 to 99 are empty;
    999999 goes to the 100th group (99 * 104 + 1 ... 106).

Thus, there will be 4 groups (i.e. four headers) and 7 numbers, so the file will occupy 4 + 7 = 11 lines.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer a

    Guaranteed constraints:
    1 ≤ a.length ≤ 105,
    1 ≤ a[i] ≤ 109.

    [output] integer

    The number of lines needed to store the grouped numbers.
*/
/* void print_int_vec(vector<int> a) {
	vector<string> result(a.size());
	for(int i=0; i< a.size(); i++){
		result[i] = to_string(a[i]);
		cout << result[i] << " " ;
	}
	cout << endl;
} */
// this only passed 12 of 15 tests.
/* int solution(vector<int> a) {
	sort(a.begin(),a.end());
	print_int_vec(a);
	cout << "a.size=" << a.size() << endl;
	int mycount=a.size();
	int x;
	float div;
	vector<int> test(100001, 0);
	for(x=0; x<a.size(); x++){
		if(a[x]/100 < 100)
			div=100.0;	 
		else if(a[x]/10000 < 10000)
			div=10000.0;
		else if(a[x]/100000 < 10000){
			if(a[x]>900000000){
				div=10000.0;
				test[(int)floor((a[x] - 10000001) / div)]=1;
				//cout << "floor((a[x] - 1) / div)=" << floor((a[x] - 1) / div) << " =" << test[(int)floor((a[x] - 1) / div)] << " div=" << div << endl;
				continue;
			}
			else div=100000.0;
		}
		else if(a[x]/1000000 < 10000)
			div=1000000.0;
		else if(a[x]/10000000 < 10000)
			div=10000000.0;
		else if(a[x]/100000000 < 10000)
			div=100000000.0;
		else if(a[x]/100000000 < 10000)
			div=100000000.0;

		test[(int)floor((a[x] - 1) / div)]=1;
		//cout << "floor2((a[x] - 1) / div)=" << floor((a[x] - 1) / div) << " =" << test[(int)floor((a[x] - 1) / div)] << " div=" << div << endl;
		//cout << "accumulate(test.begin(),test.end(),0)=" << accumulate(test.begin(),test.end(),0) << endl;
	}
	mycount+=accumulate(test.begin(),test.end(),0);
	return mycount;
} */

// this passes all tests - converted from javascript
int solution(vector<int> a) {
	int b;
	vector<int> test(100000, 0);
	for(int i=0; i<a.size(); i++)
		test[floor((a[i] - 1) / 10000)] = 1;
	
	return a.size() +  accumulate(test.begin(),test.end(),0);  //reduce(lambda a,b: a+b, []);  //test.reduce((a, b) => a + b, 0);

}


int main()
{
	int answer=0;
	vector<vector<int>> test={{1001,2002,3003,4004,5005,6006,7007,8008,9009},
									{199911000,299922000,399933000,499944000,599955000,699966000,799977000,899988000,999999000,1000001000},
									{20000, 239, 10001, 999999, 10000, 20566, 29999},
	 								{10000, 20000, 30000, 40000, 50000, 60000, 10000, 120000, 150000, 200000, 300000, 1000000, 10000000, 100000000, 10000000},
									{10000},
									{10000, 1},
									{685400881, 696804468, 696804942, 803902442, 976412678, 976414920, 47763597, 803900633, 233144924, 47764349, 233149077, 214990733, 214994039, 280528089, 280524347, 685401797},
									{598589004, 92986320, 520103781, 808743817, 635098665, 95244159, 808747008, 867017063, 635092226, 867013865, 92989995, 520100093, 95245838, 84897101, 598583113, 84893918},
									{1000000000, 999990000, 999980000, 999970000, 999960000, 999950000, 999940000, 999930000, 999920000, 999910000},
									{102382103, 21039898, 39823, 433, 30928398, 40283209, 23234, 342534, 98473483, 498398424, 9384984, 9839239}};
	vector<int> result={18,20,11,28,2,3,24,24,20,24};
	
	for(int i=0; i< test.size(); i++){
		answer=solution(test[i]);
		cout << "test#" << i << " should return " << result[i] << " and returns " << answer << endl;
	}
			
}
