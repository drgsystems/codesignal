#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
A ciphertext alphabet is obtained from the plaintext alphabet by means 
of rearranging some characters. For example "bacdef...xyz" will be a 
simple ciphertext alphabet where a and b are rearranged.

A substitution cipher is a method of encoding where each letter of the 
plaintext alphabet is replaced with the corresponding (i.e. having the same index) 
letter of some ciphertext alphabet.

Given two strings, check whether it is possible to obtain them from 
each other using some (possibly, different) substitution ciphers.

Example

    For string1 = "aacb" and string2 = "aabc", the output should be
    solution(string1, string2) = true.

    Any ciphertext alphabet that starts with acb... would make this 
	transformation possible.

    For string1 = "aa" and string2 = "bc", the output should be
    solution(string1, string2) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string string1

    A string consisting of lowercase English characters.

    Guaranteed constraints:
    1 ≤ string1.length ≤ 10.

    [input] string string2

    A string consisting of lowercase English characters of the same 
	length as string1.

    Guaranteed constraints:aa
    string2.length = string1.length.

    [output] boolean
*/

bool solution(string string1, string string2) {
    int sum1=0, sum2=0, result=0;
    if(string1.compare(string2)==0) return true;
    for(int i=0; i<string1.size()-1; i+=2){
/* 		sum1=abs(string1[i]-string1[i+1]);
		sum2=abs(string2[i]-string2[i+1]); */
        sum1+=abs(string1[i+1]-string2[i+1]);
        sum2+=abs(string1[i]-string2[i]);
		if((result=abs(sum1-sum2))) return false;
        cout << "sum1=" << sum1 << " sum2=" << sum2 << " result=" << result << endl;		
    }    
    return (true);
}

int main()
{
		vector<string> string1={{"aacb"},{"aa"},{"aaxxaaz"},{"aaxyaa"},{"aabc"},{"dccd"},{"ddcc"},{"aaaabbbbcc"},{"abcdefg"},{"aaabbbccc"}};
		vector<string> string2={{"aabc"},{"bc"},{"aazzaay"},{"aazzaa"},{"aacb"},{"zzxx"},{"zzxx"},{"cccccccccc"},{"hijklmn"},{"aaabbbccc"}};
		vector<bool> expected={true,false,true,false,true,false,true,false,true,true};
		
		for(int i=0; i<string1.size(); i++){
			int result=solution(string1[i],string2[i]);
			cout << "test#" << i+1 << " should be " << expected[i] << " returns " << result << endl;
		}
	
}

