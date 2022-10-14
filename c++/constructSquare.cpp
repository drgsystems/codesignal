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
string p_int_vec(vector<int> num){
	string result(20,{0});
	for(int i=0; i< num.size(); i++){
		result[i] = num[i] + '0';
		result[i+1] = ',';
		}
	return result;
}
int myappend(int a, int b){
	return std::stoi(std::to_string(a) + std::to_string(b));
}
int solution(string s){
	vector<char> counted(10,0);
	vector<int> num(s.length(),0);
	int digits=0;
	for(int i=0; i<s.length(); i++){
        cout << "i=" << i << " s[i]=" << s[i] << endl;
		if(find(counted.begin(), counted.end(), s[i])==counted.end()){
        //if (s[i] not in counted) {
			//num[i]=count(s.begin(),s.end(),s[i]);
            num.push_back(count(s.begin(),s.end(),s[i]));
            counted[i] = s[i];
		}
		digits = accumulate(num.begin(), num.end(), 0);
		sort(num.begin(), num.end());
		cout << "\ndigits=" <<  digits << " num=" << p_int_vec(num) << endl;
	}
    
    while(int j=(int)(ceil(pow(pow(10,digits),.5)))){
    //for(int i j in range(int(math.ceil(pow(pow(10,digits),.5))),0,-1)){
        string sq = to_string(int(pow(j,2)));
        cout << "j=" << j << " sq=" << sq <<  " pow(10,digits)=" <<  pow(10,digits) << "pow(pow(10,digits),.5)=" << pow(pow(10,digits),.5) << endl;		
        vector<int> counted(10,0);
        vector<int> numSq(10,0);

        for (int i=0; i<sq.length(); i++){
			if(find(counted.begin(), counted.end(), sq[i])==counted.end()){
            //if (sq[i] not in counted){
                numSq.push_back(count(sq.begin(),sq.end(),sq[i]));
                counted.end()-1 += sq[i];
			}
			sort(numSq.begin(), numSq.end());
			//numSq = sorted(numSq);
			cout << "numSq=" << p_int_vec(numSq) << " counted=" << p_int_vec(counted) << " sq=" << sq << "\n" << endl;
		digits-=1;
		}
		if(equal(num.begin(),num.end(),numSq.begin()))
        //if num == numSq:
            return stoi(sq);
    }
	
    return -1;
}

int main()
{

	cout << "string ab should return 81 and result is " << solution("ab") << endl;
	cout << "string zzz should return -1 and result is " << solution("zzz") << endl;
	cout << "string aba should return 900 and result is " << solution("aba") << endl;
	cout << "string abcbbb should return 810000 and result is " << solution("abcbbb") << endl;	
	cout << "string abc should return 961 and result is " << solution("abc") << endl;
	cout << "string aaaabbcde should return 999950884 and result is " << solution("aaaabbcde") << "\n" << endl;
*/
}