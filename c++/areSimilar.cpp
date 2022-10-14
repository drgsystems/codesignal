#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	std::vector<int> a = {1,1,4};
	std::vector<int> b = {1,2,3};

	int counter=0;

	for (int i=0; i <a.size(); i++) {
		if(a[i] != b[i])
			counter++;
	}

	if(counter > 2)
		return false;
		
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	for(int i=0; i<a.size(); i++)
		if(a[i] != b[i])
			return false;
	
	return true;	
}