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

bool check(std::string string1, std::string string2)
{
    std::vector<int> cypher(27, 0);
	cout<< "testing\n" ;
    for (int i = 0; i < string1.size(); ++i) {
        int cur = string1[i] - 'a' + 1;
        int mapped = string2[i] - 'a' + 1;
		cout << "cur=" << cur << " mapped=" << mapped << endl;
        if (cypher[cur] == 0) {
            cypher[cur] = mapped;
            continue;
        }
        if (cypher[cur] != mapped) {
            return false;
        }
    }
    return true;
}

bool solution(std::string string1, std::string string2) 
{
    return check(string1, string2) && check(string2, string1);
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

