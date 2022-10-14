#include <stdio.h>
#include <stdlib.h>
/*
You work in a company that prints and publishes books. You are 
responsible for designing the page numbering mechanism in the 
printer. You know how many digits a printer can print with the 
leftover ink. Now you want to write a function to determine 
what the last page of the book is that you can number given 
the current page and numberOfDigits left. A page is considered 
numbered if it has the full number printed on it (e.g. if we are 
working with page 102 but have ink only for two digits then this 
page will not be considered numbered).

It's guaranteed that you can number the current page, and that 
you can't number the last one in the book.

Example

    For current = 1 and numberOfDigits = 5, the output should be
    solution(current, numberOfDigits) = 5.

    The following numbers will be printed: 1, 2, 3, 4, 5.

    For current = 21 and numberOfDigits = 5, the output should be
    solution(current, numberOfDigits) = 22.

    The following numbers will be printed: 21, 22.

    For current = 8 and numberOfDigits = 4, the output should be
    solution(current, numberOfDigits) = 10.

    The following numbers will be printed: 8, 9, 10.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer current

    A positive integer, the number on the current page which is not yet printed.

    Guaranteed constraints:
    1 ≤ current ≤ 1000.

    [input] integer numberOfDigits

    A positive integer, the number of digits which your printer can print.

    Guaranteed constraints:
    1 ≤ numberOfDigits ≤ 1000.

    [output] integer

    The last printed page number.
*/
// this got 11/14 - kludgy
int solution1(int current, int numberOfDigits) {
    int num=0;
    if(current>99)
        num=current+(numberOfDigits/3);
    else if(current >9 && current<100){
		if((numberOfDigits-((99-current)*2))/3>199){
			num=current+(99-current)+(numberOfDigits-((99-current)*2))/3;
			//printf("num=%d\n",num);
		}
        else if((99-current)*2 < numberOfDigits)
            num=current+(99-current)+(numberOfDigits-((99-current)*2))/3-1;
        else num=current+(numberOfDigits/2)-1;
    }
    else  
        if(9-current<numberOfDigits)
            num=current+(9-current)+(numberOfDigits/2-(9-current));
        else num=current+numberOfDigits-1;

    return num;
}
// count digits per number
  int digs(int x)
{
    int res = 0;
    while (x != 0) {
        ++res;
        x /= 10;
    }
    return res;
}

int solution(int current, int numberOfDigits) 
{
    int res = 0;
    while (digs(current) <= numberOfDigits) {
        numberOfDigits -= digs(current);
        ++res;
        ++current;
		//printf("res=%d, current=%d, numberOfDigits=%d\n",res,current,numberOfDigits);
    }
    return current - 1;
}

int main()
{
	int test[10][3]={{1,5,5},
					{21,5,22},
					{8,4,10},
					{21,6,23},
					{10,3,10},
					{76,250,166},
					{80,1000,419},
					{150,100,182},
					{250,12,253},
					{300,1000,632}};
	for(int i=0; i<10; i++)
		printf("current=%d,numdigits=%d,expected=%d,result=%d\n",test[i][0],test[i][1],test[i][2],solution(test[i][0],test[i][1]));
		

}
