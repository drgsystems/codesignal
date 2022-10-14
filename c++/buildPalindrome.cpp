#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
Given a string, find the shortest possible string which 
can be achieved by adding characters to the end of initial 
string to make it a palindrome.

Example

For st = "abcdc", the output should be
solution(st) = "abcdcba".

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string st

    A string consisting of lowercase English letters.

    Guaranteed constraints:
    3 ≤ st.length ≤ 10.

    [output] string
*/
bool check_pal(string st){
  string temp(st.length(),{0});
  int i=0;
  // reverse string
    for (std::string::reverse_iterator rit=st.rbegin(); rit!=st.rend(); ++rit)
    		temp[i++]=*rit;
   //check if temp is palindrom of st
  return((st.compare(temp)==0) ? true : false);
}
string solution(string st) {
  string temp(st.length(),{0});
  // make copy of st
  temp=st.substr(0,st.length());
  int i=0,j=0,first;
  // check if already a palindrome
  if(check_pal(st)) return st;
  // start appending chars to temp from start of st till palindrome found
  for(i=0; i<st.length()-1; i++){
    //append to temp descending characters from 0
    for(j=i; j>=0; j--){
      temp.push_back(temp[j]);  
    }
    cout << "push=" << temp << endl;
	// if palindrome you're done
    if(check_pal(temp)){ 
      return temp;
    }
	// if not, pop all you pushed
    else{
      for(j=i; j>=0; j--){
        temp.pop_back();
        cout << "pop="<< temp << endl;
      }
    }
    
  }
  return temp;
}


int main() 
{
	string test1 ("abaa");
	cout << endl << test1 << " " << solution(test1) << endl;
}


if(st[(first=st.rfind(st[st.length()-1]))]==st[st.length()-1])