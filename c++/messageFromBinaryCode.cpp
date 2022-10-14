#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;
using std::to_string;

/*
You are taking part in an Escape Room challenge designed specifically 
for programmers. In your efforts to find a clue, you've found a binary 
code written on the wall behind a vase, and realized that it must be 
an encrypted message. After some thought, your first guess is that each 
consecutive 8 bits of the code stand for the character with the corresponding 
extended ASCII code.

Assuming that your hunch is correct, decode the message.

Example

For code = "010010000110010101101100011011000110111100100001", the output 
should be solution(code) = "Hello!".

The first 8 characters of the code are 01001000, which is 72 in the binary 
numeral system. 72 stands for H in the ASCII-table, so the first letter is H.
Other letters can be obtained in the same manner.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string code

    A string, the encrypted message consisting of characters '0' and '1'.

    Guaranteed constraints:
    0 < code.length < 800.

    [output] string

    The decrypted message.
*/

string binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return to_string(dec_value);
}
string stringToAscii(string data) {
	// this is typedef to input data
	std::stringstream sstream(data);
	std::string output;
	// this can be good() or !eof()
	while(!sstream.eof())
	{
		std::bitset<8> bits;
		sstream >> bits;
		// last char will be a ulong '\0000'
		char c = char(bits.to_ulong());
		output += c;
	}
	//std::cout << output;
	return output;
}

string solution(string code) {
	string message;
	string letter;
/* 	for(int i=0; i<code.length(); i+=8)
		letter.append(code,i,8); */
	letter=stringToAscii(code);
	//message.append(letter);
	
	//cout << message << endl;
	//letter.pop_back();
	return letter;
}

int main()
{
	string test1={"010010000110010101101100011011000110111100100001"};  // Hello
	string test2={"01001101011000010111100100100000011101000110100001\
	10010100100000010001100110111101110010011000110110010100100000011\
	00010011001010010000001110111011010010111010001101000001000000111\
	10010110111101110101"};  // May the Force be with you
	string test3={"01011001011011110111010100100000011010000110000101\
	10010000100000011011010110010100100000011000010111010000100000011\
	00000011010000110010101101100011011000110111100101110"};  // You had me at `hello.
	string test4={"01000101011011000110010101101101011001010110111001\
	11010001100001011100100111100100101100001000000110110101111001001\
	00000011001000110010101100001011100100010000001010111011000010111\
	010001110011011011110110111000100001"};  // Elementary, my dear Watson!
	
	cout << "test1=" << test1 << endl << solution(test1) << endl;
/* 	cout << "test2=" << test2 << endl;
	cout << "test3=" << test3 << endl;
	cout << "test4=" << test4 << endl; */
	
}