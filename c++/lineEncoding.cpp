#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a string, return its encoding defined as follows:

    First, the string is divided into the least possible number of disjoint substrings consisting of identical characters
        for example, "aabbbc" is divided into ["aa", "bbb", "c"]
    Next, each substring with length greater than one is replaced with a concatenation of its length and the repeating character
        for example, substring "bbb" is replaced by "3b"
    Finally, all the new strings are concatenated together in the same order and a new string is returned.

Example

For s = "aabbbc", the output should be
solution(s) = "2a3bc".

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string s

    String consisting of lowercase English letters.

    Guaranteed constraints:
    4 ≤ s.length ≤ 15.

    [output] string

    Encoded version of s.
*/


string solution(string s) {
   // count number of chars in sequence
    // if greater than 1 replace first char with number of chars in substring
    string temp;
    int i=0,j=0,count=1;
    while(s[j]!='\0'){
        char mychar=s[j++];
        count++;
        if(mychar!=s[j]){
            count--;
            if(count>1)              
                temp.append(to_string(count));
            temp.append(s,j-1,1);
            count=1;
        }           
    }
    return temp;
}

int main()
{


}