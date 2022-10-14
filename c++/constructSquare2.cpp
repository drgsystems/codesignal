#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>


using namespace std;


/*
# Given a string consisting of lowercase English letters, find the largest 
# square number which can be obtained by reordering the string's characters 
# and replacing them with any digits you need (leading zeros are not allowed) 
# where same characters always map to the same digits and different characters 
# always map to different digits.

# If there is no solution, return -1.

# Example

    # For s = "ab", the output should be
    # solution(s) = 81.
    # The largest 2-digit square number with different digits is 81.
    # For s = "zzz", the output should be
    # solution(s) = -1.
    # There are no 3-digit square numbers with identical digits.
    # For s = "aba", the output should be
    # solution(s) = 900.
    # It can be obtained after reordering the initial string into "baa" and 
	# replacing "a" with 0 and "b" with 9.

# Input/Output

    # [execution time limit] 0.5 seconds (cpp)

    # [input] string s

    # Guaranteed constraints:
    # 1 ≤ s.length < 10.

    # [output] integer
*/
string p_char_vec(vector<char> num){
	string result(num.size(),{0});
	for(int i=0; i< num.size(); i++){
		result[i] = num[i];
		}
	return result;
}

string p_int_vec(vector<int> num){
	string result(num.size(),{0});
	for(int i=0; i< num.size(); i++){
		result[i] = num[i] + '0';
		}
	return result;
}

int solution(string s){
	vector<char> counted(s.length(),0);
	vector<int> num(s.length(),0);
	int digits=0;
	for(int i=0; i<s.length(); i++){
		if(find(counted.begin(), counted.end(), s[i])==counted.end()){
			//num[i]=count(s.begin(),s.end(),s[i]);
			num.push_back(count(s.begin(),s.end(),s[i]));
            counted[i] = s[i];
		}
		digits = accumulate(num.begin(), num.end(), 0);
		sort(num.begin(), num.end());
		//cout << " i=" << i << " s[i]=" << s[i] << " counted=" << p_char_vec(counted) << "\n digits=" <<  digits << " num=" << stoi(p_int_vec(num)) << endl;
	}

    int j=(int)(ceil(pow(pow(10,digits),.5)));
    while(j){
        string sq = to_string(int(pow(j,2)));
        //cout << "digits=" << digits << " j=" << j << " sq=" << sq <<  " pow(10,digits)=" <<  pow(10,digits) << " pow(pow(10,digits),.5)=" << pow(pow(10,digits),.5) << endl;		
        vector<char> counted(s.length(),0);
        vector<int> numSq(s.length(),0);

        for (int i=0; i<sq.length(); i++){
			if(find(counted.begin(), counted.end(), sq[i])==counted.end()){
				numSq.push_back(count(sq.begin(),sq.end(),sq[i]));
				counted[i]=sq[i];
			}
			sort(numSq.begin(), numSq.end());
		}
		j--;
		//cout << "numSq=" << p_int_vec(numSq) << " counted=" << p_char_vec(counted) << " sq=" << sq << "\n" << endl;
		if(equal(num.begin(),num.end(),numSq.begin()) && equal(numSq.begin(),numSq.end(),num.begin()))
            return stoi(sq);
    }
	
    return -1;
}

int main()
{
	int result=0;
	result=solution("ab");
	cout << "string ab should return 81 and result is " << result << endl;
	result=solution("zzz");
 	cout << "string zzz should return -1 and result is " << result << endl;
	result=solution("aba");
	cout << "string aba should return 900 and result is " << result << endl;
	result=solution("abcbbb");
	cout << "string abcbbb should return 810000 and result is " << result << endl;
	result=solution("abc");	
	cout << "string abc should return 961 and result is " << result << endl;
		result=solution("aaaabbcde");
	cout << "string aaaabbcde should return 999950884 and result is " << result << "\n" << endl; 

}