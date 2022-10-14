#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <string>

using namespace std;

/*
Given an array of equal-length strings, you'd like to know if it's 
possible to rearrange the order of the elements in such a way that 
each consecutive pair of strings differ by exactly one character. 
Return true if it's possible, and false if not.

Note: You're only rearranging the order of the strings, not the 
order of the letters within the strings!

Example

    For inputArray = ["aba", "bbb", "bab"], the output should be
    solution(inputArray) = false.

    There are 6 possible arrangements for these strings:
        ["aba", "bbb", "bab"]
        ["aba", "bab", "bbb"]
        ["bbb", "aba", "bab"]
        ["bbb", "bab", "aba"]
        ["bab", "bbb", "aba"]
        ["bab", "aba", "bbb"]

    None of these satisfy the condition of consecutive strings 
	differing by 1 character, so the answer is false.

    For inputArray = ["ab", "bb", "aa"], the output should be
    solution(inputArray) = true.

    It's possible to arrange these strings in a way that each 
	consecutive pair of strings differ by 1 character 
	(eg: "aa", "ab", "bb" or "bb", "ab", "aa"), so return true.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.string inputArray

    A non-empty array of strings of lowercase letters.

    Guaranteed constraints:
    2 ≤ inputArray.length ≤ 10,
    1 ≤ inputArray[i].length ≤ 15.

    [output] boolean

    Return true if the strings can be reordered in such a way 
	that each neighbouring pair of strings differ by exactly 
	one character (false otherwise).
*/
void printVector(vector<string> mat) {
    for (int i=0; i< mat.size(); i++){
        cout << mat[i] << " ";
	}
	cout << endl;
}

/* bool solution(vector<string> inputArray) {
	char ch={' '};
	bool same=false;
	int i;
	// check if strings same
    for(i=0; i<inputArray.size(); i++){
		ch=inputArray[i][0];
        for(int j=1; j<inputArray.size(); j++){
            if(inputArray[i].compare(inputArray[j])==0)
                return false;
			else if(inputArray[j].find(ch) != std::string::npos)
				same=true;
			//else same=false;
		}
		if(same==true) return true;			
	}
	return same;      
} */
int dist(const std::string& s1, const std::string& s2)
{
    int c = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++c;
        }
    }
    return c;
}

bool check(const std::vector<std::string>& a)
{
    for (int i = 0; i < a.size() - 1; ++i) {
        if (dist(a[i], a[i + 1]) != 1) {
            return false;
        }
    }
    return true;
}

bool solution(std::vector<std::string> inputArray) 
{
    std::sort(inputArray.begin(), inputArray.end());
    if (check(inputArray)) {
        return true;
    }
    while (std::next_permutation(inputArray.begin(), inputArray.end())) {
        if (check(inputArray)) {
            return true;
        }
    }
    return false;
} 

int main()
{
	vector<string> test1={"aba", "bbb", "bab"};
	vector<string> test2={"ab", "bb", "aa"};
	vector<string> test3={"q", "q"};
	vector<string> test4={"abc", "bef", "bcc", "bec", "bbc", "bdc"};
	vector<string> test5={"abc", "abx", "axx", "abx", "abc"};
	vector<string> test6={ "f", "g", "a", "h"};
	vector<string> test7={"a", "b", "c"};
	
	cout << "test2=" ;
	printVector(test2);
	cout << " should be true, result=" << (solution(test2) ? "True" : "False") << endl;
	
	cout << "test1=" ;
	printVector(test1);
	cout << " should be false, result=" << (solution(test1) ? "True" : "False") << endl;
	
	cout << "test3=" ;
	printVector(test3);
	cout << " should be false, result=" << (solution(test3) ? "True" : "False") << endl;
	
	cout << "test4=" ;
	printVector(test4);
	cout << " should be true, result=" << (solution(test4) ? "True" : "False") << endl;
	
	cout << "test5=" ;
	printVector(test5);
	cout << " should be true, result=" << (solution(test5) ? "True" : "False") << endl;
	
	cout << "test6=" ;
	printVector(test6);
	cout << " should be true, result=" << (solution(test6) ? "True" : "False") << endl;
	
	cout << "test7=" ;
	printVector(test7);
	cout << " should be true, result=" << (solution(test7) ? "True" : "False") << endl;
}