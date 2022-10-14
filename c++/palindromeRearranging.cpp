#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
Given a string, find out if its characters can be rearranged to form a palindrome.

Example

For inputString = "aabb", the output should be
solution(inputString) = true.

We can rearrange "aabb" to make "abba", which is a palindrome.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string inputString

    A string consisting of lowercase English letters.

    Guaranteed constraints:
    1 ≤ inputString.length ≤ 50.

    [output] boolean

    true if the characters of the inputString can be rearranged to form a palindrome, false otherwise.
*/
#define TRUE 1
#define FALSE 0

void reverse(string& mystring,int len)
{
	char temp;

	for (int i=0; i < len; i++){
		temp=mystring[i];
		mystring[i]=mystring[len-i-1];
		mystring[len]=temp;
	}
}

bool solution(string inputString) {
	int len=inputString.length(),odd=0;
	string temp=inputString;
	// reverse and check if same
/* 	reverse(inputString,len);
	if(temp.compare(inputString))
		return FALSE;
	else return TRUE; */

	// count all even and odd characters
	// if more than one character is odd
	// not a palindrome
	// restriction is string is lower case english letters
	int chars[26]={0};
	for(int i=0; i<len; i++)
		chars[inputString[i]-97]++;
	
	for(int i=0; i<26; i++) {
		if(chars[i] != 0) {
			if(chars[i] %2 != 0){
				odd++;
				if(odd > 1)
					return FALSE;
			}
		}
	}
	if(odd < 2)
		return TRUE;
	return FALSE;
}

int main()
{

	string inputString1={"afgcd"};
	string inputString2={"auauhgjauauhgj980098"};
	string inputString3={"abcdcba"};
	string inputString4={"aabbccdddccbbaa"};
	string inputString5={"aaaabbbbccccddd"};

	cout << "is string " << inputString1 << " a palindrome? " << (solution(inputString1) ? "True" : "False") << "\n";
	cout << "is string " << inputString2 << " a palindrome? " << (solution(inputString2) ? "True" : "False") << "\n";
	cout << "is string " << inputString3 << " a palindrome? " << (solution(inputString3) ? "True" : "False") << "\n";
	cout << "is string " << inputString4 << " a palindrome? " << (solution(inputString4) ? "True" : "False") << "\n";
	cout << "is string " << inputString5 << " a palindrome? " << (solution(inputString5) ? "True" : "False") << "\n";

}



