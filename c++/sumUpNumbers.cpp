#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string inputString)
{
    string num={"\0"};
    int i=0,digits=0;
    //if(num.length()==0) return digits;
    for(i=0; i<inputString.length(); i++){
        if(isdigit(inputString[i]))
            num.append(&inputString[i],1);
        else {
            if(num.length() >0){
                digits+=stoi(num);
                num={"\0"};
            }
            cout << num << endl;
        }
    }
    if(num.length()>0)
        digits+=stoi(num);
    cout << "num=" << num << " digits=" << digits << endl;
    return digits;
}

int main()
{
	string test1={"abcdefghijklmnopqrstuvwxyz1AbCdEfGhIjKlMnOpqrstuvwxyz23,74 -"};
	string test2={"there are some (12) digits 5566 in this 770 string 239"};
	
}