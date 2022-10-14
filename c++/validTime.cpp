#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
Check if the given string is a correct time representation of the 
24-hour clock.

Example

    For time = "13:58", the output should be
    solution(time) = true;
    For time = "25:51", the output should be
    solution(time) = false;
    For time = "02:76", the output should be
    solution(time) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string time

    A string representing time in HH:MM format. It is guaranteed 
	that the first two characters, as well as the last two characters, 
	are digits.

    [output] boolean

    true if the given representation is correct, false otherwise.
*/

bool solution(string time) {
    if(time.length()>5) return false;
    string hour=(2,time.substr(0,2));
    string min=(2,time.substr(3,2));
    cout << hour << " " << min << endl;
    if(stoi(hour) > 23) return false;
    if(stoi(min) > 59) return false;
    return true;    
}

int main()
{


}

