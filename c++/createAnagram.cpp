#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
You are given two strings s and t of the same length, consisting of 
uppercase English letters. Your task is to find the minimum number of 
"replacement operations" needed to get some anagram of the string t 
from the string s. A replacement operation is performed by picking e
xactly one character from the string s and replacing it by some other 
character.

Example

    For s = "AABAA" and t = "BBAAA", the output should be
    solution(s, t) = 1;
    For s = "OVGHK" and t = "RPGUC", the output should be
    solution(s, t) = 4.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string s

    Guaranteed constraints:
    5 ≤ s.length ≤ 35.

    [input] string t

    Guaranteed constraints:
    t.length = s.length.

    [output] integer

    The minimum number of replacement operations needed to get an 
	anagram of the string t from the string s.
*/

int solution(string s, string t) {
    int change = 0;

	vector<int> tally(26,{0});
	int cnt=0,i;
	
	for(i=0; i<s.size(); i++)
		tally[s[i]-'A']++;
	
	for(i=0; i<t.size(); i++)
		tally[t[i]-'A']--;
	
	for(i=0; i<26; i++)
		if(tally[i]>0) cnt+=tally[i];
	
	return cnt;
}


int main()
{
	vector<string> stringS={{"AABAA"},{"OVGHK"},{"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB"},
							{"HDFFVR"},{"AABCDS"},{"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZY"},
							{"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"},{"AAAAAA"},
							{"KJDMDLEEKALIJB"},{"BBAAABCBCAABB"}};
	vector<string> stringT={{"BBAAA"},{"RPGUC"},{"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAC"},
							{"FEDDEE"},{"BASEAE"},{"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYZ"},
							{"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"},{"AAAAAA"},
							{"AFDJGDCGHMIGHB"},{"BBBCCCBABBACA"}};
	vector<int> result={1,4,1,4,2,31,0,0,7,2};
	
	for(int i=0; i<stringS.size(); i++){
		int myresult=solution(stringS[i],stringT[i]);
		cout << "stringS[" << i << "] should be " << result[i] << " and returns " << myresult << endl;
		
	}
}
