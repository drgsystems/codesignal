#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*

*/

void printVector(vector<int> mat) {
    for (int i=0; i< mat.size(); i++){
        cout << mat[i] << " ";
	}
	cout << endl;
}
int solution(int n) {
	int counter=0;
	while(n>=10){
		counter++;
		int sum = 0;
		while(n>0) {
			sum+= n%10;
			n/=10;
		}
		n=sum;
	}
	return counter;
}

int solution1(int n) {
   int i=n,result=0, sum=1;
    if(n <10) return 0;
    else if (n<=100 && n%10==0) return 1;
    else if(n<=99 && (n/10 + n%10)>9) return 2;
    // sum all digits
    while(i){
        //i%=10;
        cout << "i=" << i << endl;
        result+=i%10;
        cout << "result=" << result << endl;
        // if(i%10) sum++;
        cout << "sum=" << sum << endl;
        i/=10;
    }
    if(result<10) return sum;
    //if(result>10) sum++;
    while(result>10){
        result/=10;
        cout << "result2=" << result << endl;
        sum++;
        
    }
    cout << sum;
    return sum;
}

int solution(int value1, int weight1, int value2, int weight2, int maxW) {

}

int main()
{


}
