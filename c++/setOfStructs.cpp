#include <iostream>
#include<set>
using namespace std;

// struct of a car
struct Car
{
    int m;
    int p;
    void set(int a,int b){
        m =a,p = b;
    }
};
// instantiate set of Car structs
struct Car cT[50];
// instantiate an integer counter
int cI=0;

bool operator < (const Car& c1,const Car& c2){
    return c1.p < c2.p;
}
// insert formatted output into operator ptr of type ostream
ostream& operator << (ostream& o, const Car& a){
	o << "Car Model: " << a.m << " price: " << a.p << endl;
	return o;
}
// insert a car into set of cars
void insertS(set<Car>& c){
    for(int i=0;i<cI;i++){
        c.insert(cT[i]);
    }
}
// print set of Car pointers
void printS(set<Car> c){
    set<Car> :: iterator i;
    for( i=c.begin();i!=c.end();i++){
        cout << *i<<endl;
    }
}

int main() {
    // Write C++ code here
    set<Car> mCs;
    cT[cI++].set(4,5);
    cT[cI++].set(34,4);
    cT[cI++].set(43,6);
    cT[cI++].set(41,15);
    insertS(mCs);
    printS(mCs);

    return 0;
}