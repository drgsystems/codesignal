#include <iostream>
#include <string>
using namespace std;

/*
An IP address is a numerical label assigned to each device (e.g., 
computer, printer) participating in a computer network that uses 
the Internet Protocol for communication. There are two versions 
of the Internet protocol, and thus two versions of addresses. 
One of them is the IPv4 address.

Given a string, find out if it satisfies the IPv4 address naming rules.

Example

    For inputString = "172.16.254.1", the output should be
    solution(inputString) = true;

    For inputString = "172.316.254.1", the output should be
    solution(inputString) = false.

    316 is not in range [0, 255].

    For inputString = ".254.255.0", the output should be
    solution(inputString) = false.

    There is no first number.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string inputString

    A string consisting of digits, full stops and lowercase English letters.

    Guaranteed constraints:
    1 ≤ inputString.length ≤ 30.

    [output] boolean

    true if inputString satisfies the IPv4 address naming rules, false otherwise.
*/

bool solution(string inputString) {
	
	int i,addr=0,dec_count;
	char dp= '.', digits[4]={0};
	
	for(i=0; i, inputString.size(); i++)
	{
		digits[i%4]=inputString[i];
		if(inputString[i]==dp){
			dec_count++;
			if(dec_count > 3) return false;
		}
	}		
	return true;		
}
/* 
bool solution(string inputString) {
	std::string delimiter = ".";

	size_t pos = 0;
	std::string token;
	int dec_count=0, addr_byte=0;
	//while (dec_count<3) {
	for(int i=0; i<4; i++){
		if(i>2)
			pos=inputString.length();
		else
			pos = inputString.find(delimiter);
		cout << "pos=" << pos << "\n";
		dec_count++;
		if(i>=2 && dec_count < 3 || pos >3) {
			cout << "false1\n";
			return false;
		}
		token = inputString.substr(0, pos);
		// check for blank
		if(token.length() <1){
			cout << "false2\n";
			return false;
		}// check for digit
		for (char const &c : token) {
			if (std::isdigit(c) == 0) {
				cout << "false\n";
				return false;
			}
		}
		// erase previous string
		inputString.erase(0, pos + delimiter.length());
		// convert to number
		addr_byte=stoi(token);
		cout << addr_byte << "\n";
		// check if in bounds
		if(addr_byte < 0 || addr_byte>255 ) {
			cout << "false3\n";
			return false;
		}
		
	}
	cout << inputString << endl;

	if(inputString.size()) return false;
	
	cout << "true\n";	
	return true;
} */

int main()
{
	// a valid ipv4 address consists of 4 8 bit values (0-255)
	// separated by a decimal point ( total of 3 in address).
	
	//std::string s = {"125.33.98.240"};
	std::string inputString = {"172.16.254.00"};
	std::string delimiter = ".";

	size_t pos = 0;
	std::string token;
	int dec_count=0, addr_byte=0;
	//while (dec_count<3) {
	for(int i=0; i<4; i++){
		if(i>2)
			pos=inputString.length();
		else
			pos = inputString.find(delimiter);
		dec_count++;
		if(i>=2 && dec_count < 3 || pos >3) {
			cout << "false1\n";
			return false;
		}
		token = inputString.substr(0, pos);
		// check for blank
		if(token.length() <1 || (token.length()>1 && token[0]=='0')){
			cout << "false2\n";
			return false;
		}// check for digit
		for (char const &c : token) {
			if (std::isdigit(c) == 0) {
				cout << "false3\n";
				return false;
			}
		}
		// erase previous string
		inputString.erase(0, pos + delimiter.length());
		// convert to number
		addr_byte=stoi(token);
		cout << addr_byte << "\n";
		// check if in bounds
		if(addr_byte < 0 || addr_byte>255 ) {
			cout << "false4\n";
			return false;
		}
		
	}
	cout << inputString << endl;

	if(inputString.size()) return false;
	
	cout << "true\n";	
	return true;
}	
