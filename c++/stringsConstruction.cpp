#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
Given two strings a and b, both consisting only of lowercase English 
letters, your task is to calculate how many strings equal to a can be 
constructed using only letters from the string b? Each letter can be 
used only once and in one string only.

Example

    For a = "abc" and b = "abccba", the output should be solution(a, b) = 2.

    We can construct 2 strings a = "abc" using only letters from the string b.

    For a = "ab" and b = "abcbcb", the output should be solution(a, b) = 1.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string a

    String to construct, containing only lowercase English letters.

    Guaranteed constraints:
    1 ≤ a.length ≤ 105.

    [input] string b

    String containing needed letters, containing only lowercase English letters.

    Guaranteed constraints:
    1 ≤ b.length ≤ 105.

    [output] integer

    The number of strings a that can be constructed from the string b.
*/

int solution(string a, string b) {
    if(a.size() > b.size()) return 0;
	int tallyA=0,tallyB=0,result=b.size();

	for(int i=0; i<26; i++){
		tallyA=0; tallyB=0;
		for(int j=0; j<a.size(); j++)
			if(a[j]=='a'+i) tallyA++;
		for(int j=0; j<b.size(); j++)
			if(b[j]=='a'+i) tallyB++;
		if(tallyA ==0){
			continue;
		}
		result=(result<tallyB/tallyA)? result:tallyB/tallyA;
	}
	return result;

}
int main()
{
	vector<string> a={{"za"},{"z"},{"abc"},{"ab"},{"pqrsttt"},{"abcabcabc"},{"zzz"}};
	vector<string> b={{"bzc"},{"y"},{"abccba"},{"abcbcb"},{"parfkajfraqrakjssattertjeqsqaptatdptdstasreraqprtt"},{"aaaaaaaaaaabbbbbbbbbbcccccccccc"},{"zzzzzzzzzzz"}};
	vector<int> result={0,0,2,1,3,3,3};
	int myresult=0;
	for(int i=0; i<a.size(); i++){
		myresult=solution(a[i],b[i]);
		cout << "test#" << i << " should be " << result[i] << " and is " << myresult << endl;
	}

}