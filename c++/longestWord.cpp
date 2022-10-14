#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
Define a word as a sequence of consecutive English 
letters. Find the longest word from the given string.

Example

For text = "Ready, steady, go!", the output should be
solution(text) = "steady".

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string text

    Guaranteed constraints:
    4 ≤ text.length ≤ 50.

    [output] string

    The longest word from text. It's guaranteed that 
	there is a unique output.
*/

/* string solution(string text) {

} */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// works 8 of 10 tests
string solution(string text){
    string longest;
	vector<string> words(50,{"0"});
	int i=0, j=0;
    cout << (text.size()) << endl;
    for(i=0; i<text.size(); i++){
        if(isalpha(text[i])){
            longest.append(&text[i],1);
			cout << "text=" << text[i] << " longest=" << longest << endl;
		}
        else if(text[i]==' ' || !isalpha(text[i])){
			words[j]=longest.substr(0,longest.length());
			longest.assign("\0");
			cout << words[j] << endl;
			j++;
		}
    }
    cout << "words[0]=" << words[0] << "words[1]=" << words[1] << "words[2]=" << words[2] << endl;
    for(int x=0; x<words.size(); x++)
        if(words[x].size() > longest.size())
            longest=words[x];
    cout << "longest=" << longest << endl;
    return longest;   
}

/* string solution(string text) {  //java solution
	text=text.replaceAll("[^a-zA-Z]+", " ");
	vector<string> words(50,{"0"});
	//String[] words = text.split(" ");
	words = text.split(" ");
	string mymax = words[0];
	for(string word: words) {
		if(word.length() > mymax.length()){
			mymax=word;
		}
	}
	return mymax;
} */

int main()
{
		string test1=("Ready, steady, go!"), test2=("You are the best!!!!!!!!!!!! CodeFighter ever!");
		
		cout << "test1=" << test1 << " longest word=" << solution(test1) << endl;
		cout << "test2=" << test2 << " longest word=" << solution(test2) << endl;
}