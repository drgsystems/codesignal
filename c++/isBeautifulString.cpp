#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_CHAR 26

bool solution(string inputString) {
    int chars[MAX_CHAR]={0}; int i;
    for(i=0; i<inputString.length(); i++)
        chars[inputString[i]-'a']++;
    for(i=1; i<MAX_CHAR; i+=2)
        if((chars[i]!=chars[i-1])  || chars[i]==0 || chars[i-1]==0) return false;
    return true;
}


int main()
{
	string inputString1={"bbbaacdafe"};
	string inputString={"abcdefghijklmnopqrstuvwxyzz"};
	string inputString2={"abcdefghijklmnopqrstuvwxyzqwertuiopasdfghjklxcvbnm"};
 /*    int chars[MAX_CHAR]={0}; int i,lowest_char=inputString[0]-'a';
    for(i=0; i<inputString.length(); i++){
		chars[(inputString[i]-'a')]++;
		cout << "char=" << inputString[i] << " chars[inputString[i]-a]=" << (chars[(inputString[i]-'a')]) << endl;
		if(lowest_char>(inputString[i]-'a'))
			lowest_char=inputString[i]-'a';
		cout << "lowest_char=" << lowest_char << endl;
	}
	cout << "inputString=" << inputString.length() << endl;
    for(i=0; i<MAX_CHAR; i+=2){
		cout << "i=" << i << " chars[i]=" << chars[i] << " chars[i+1]=" << chars[i+1] << endl;
        if((chars[i+lowest_char]!=chars[i+lowest_char+1])){
			cout << "false";
			return false;
		}
	}
    cout << "true";
	return true; */
	int cur = std::count(inputString.begin(),inputString.end(), 'a');
	cout << "count of a=" << cur << endl;
	for (int i = 1; i < 26; i++) {
		int temp = count(inputString.begin(), inputString.end(), 'a' + i);
		cout << "temp=" << temp << endl;
		if(temp > cur) {
			cout << "false" << endl;
			return false;
		}
		cur = temp;
	}
	cout << "true\n";
	return true;
}
