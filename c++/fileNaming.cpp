#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>


using namespace std;
using std::to_string;

/*
You are given an array of desired filenames in the order of their creation. Since two files cannot have equal names, the one which comes later will have an addition to its name in a form of (k), where k is the smallest positive integer such that the obtained name is not used yet.

Return an array of names that will be given to the files.

Example

For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
solution(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.string names

    Guaranteed constraints:
    5 ≤ names.length ≤ 1000,
    1 ≤ names[i].length ≤ 15.

    [output] array.string
*/
/* vector<string> solution1(vector<string> names) {
	string myappend;
	for(int i=0; i<names.size(); i++){
		int count=1;
		for(int j=0; j<names.size(); j++){
			cout << names[i] << endl;            
			if(names[i].compare(names[j])==0 && i!=j){
				names[j].append('('+to_string(count)+')');
				count++;
			}
		}    
	}
	return names;
}
// worked for 4 out of 6
vector<string> solution2(vector<string> names) {
    string myappend;
    for(int i=0; i<names.size(); i++){
        int count=1;
        for(int j=i; j<names.size(); j++){
            cout << names[i] << endl;            
            if(names[i].compare(names[j])==0 && i!=j){
                myappend='0';
                myappend.append(names[j]+'('+to_string(count)+')');
                if(names[i].compare(myappend)==0 && i!=j){
                    count++;
                    names[j].append('('+to_string(count)+')');
                }
                else
                    names[j].append('('+to_string(count)+')');
                count++;
            }
        }    
    }
    return names;
} */

void printVecString(vector<string> mystrings) {
	cout << endl;
	for(int i=0; i<mystrings.size(); i++)
		cout << mystrings[i] << endl;
	cout << endl;
}

// print set of strings using pointers to each set element
void printS(set<string> c){
    set<string> :: iterator i;
    for( i=c.begin(); i!=c.end();i++){
        cout << *i << "\n";
    }
	cout << endl;
}

void print_set_element(set<string> setOfStr, int index) {
	if(setOfStr.size() > index)
	{
		std::set<std::string>::iterator it = std::next(setOfStr.begin(), index);
		std::cout<<"Element " << index << " in set = "<<*it<<std::endl;
	}
}


// youtube solution
std::vector<std::string> solution(std::vector<std::string> names) 
{
	std::set<std::string> a;
    for (int i = 0; i < names.size(); ++i) {
		cout << "step1" << " i=" << i << " names[i]=" << (names[i]) << endl;
        if (a.find(names[i]) == a.end()) {
            a.insert(names[i]);
			cout << "a.insert(names[i]) before a.end , continue find1" << endl;
            continue;
        }
		cout << "step2" << " i=" << i << endl;
        for (int j = 1; j <= names.size() + 1; ++j) {
            auto name = names[i] + "(" + std::to_string(j) + ")";
            if (a.find(name) != a.end()) {
				cout << "name found in a set, need to increment j ctr - continue find2" << " j=" << j << " name=" << name << endl;
                continue;
            }
			cout << "step3" << " j=" << j << " i=" << i << " names[i]=" << name << endl;
            names[i] = name;
            a.insert(name);
			cout << "insert " << name << " into a =" << endl;
			printS( a);
			
            break;
        }
		cout << "step4 at end of for i loop" << " i=" << i << " names[i]=" << names[i] << endl;
		printVecString(names);
    }
    
    return names;
}
int main()
{
	vector<string> test1={"a(1)",  // "a(1)","a(6)","a","a(2)","a(3)","a(4)","a(5)","a(7)","a(8)","a(9)","a(10)","a(11)"
						 "a(6)", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a", 
						 "a"};
	vector<string> test2={"dd",  // "dd","dd(1)","dd(2)","dd(3)","dd(1)(1)","dd(1)(2)","dd(1)(1)(1)","dd(4)","dd(1)(3)"
						 "dd(1)", 
						 "dd(2)", 
						 "dd", 
						 "dd(1)", 
						 "dd(1)(2)", 
						 "dd(1)(1)", 
						 "dd", 
						 "dd(1)"};	

	cout << "test1=\n"; printVecString(test1);
	cout << "solution=\n"; printVecString(solution(test1));
/* 	cout << "test2=\n"; printVecString(test2);
	cout << "solution=\n"; printVecString(solution(test2)); */
}

