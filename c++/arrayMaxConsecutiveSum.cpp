#include <iostream>
#include <vector>

using namespace std;

/*

*/
void printVector(vector<int> mat) {
    for (int i=0; i< mat.size(); i++){
        cout << mat[i] << " ";
	}
	cout << endl;
}

int solution(vector<int> inputArray, int k) {
    int i,j,sumk=0, result=0;
    for(i=0; i<inputArray.size()-k+1; i++){
		for(j=0; j<k; j++)
			sumk+=inputArray[i+j];
		if(sumk>result)
			result=sumk;
		sumk=0;
	}
	return result;
}

int main()
{
	vector<int> test1{2, 3, 5, 1, 6};
	vector<int> test2{1, 3, 2, 4};
	vector<int> test3{1, 3, 4, 2, 4, 2, 4};
	
	printVector(test1);
	cout << " k=2, answer should be 8, result=" << (solution(test1,2)) << endl;
	
	printVector(test2);
	cout << " k=3, answer should be 9, result=" << (solution(test2,3)) << endl;

	printVector(test3);
	cout << " k=4, answer should be 13, result=" << (solution(test3,4)) << endl;

}