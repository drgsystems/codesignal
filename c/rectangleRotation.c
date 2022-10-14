#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
A rectangle with sides equal to even integers a and b is drawn on the 
Cartesian plane. Its center (the intersection point of its diagonals) 
coincides with the point (0, 0), but the sides of the rectangle are not 
parallel to the axes; instead, they are forming 45 degree angles with the axes.

How many points with integer coordinates are located inside the given 
rectangle (including on its sides)?

Example

For a = 6 and b = 4, the output should be
solution(a, b) = 23.

The following picture illustrates the example, and the 23 points are marked green.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] integer a

    A positive even integer.

    Guaranteed constraints:
    2 ≤ a ≤ 50.

    [input] integer b

    A positive even integer.

    Guaranteed constraints:
    2 ≤ b ≤ 50.

    [output] integer

    The number of inner points with integer coordinates.
*/
// be sure to compile with math library - "gcc -g rectangleRotation.c -lm" 
#define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

int solution(int a, int b) {
    float aHalfBisect = (a/sqrt(2))/2;
    float bHalfBisect = (b/sqrt(2))/2;
    float rect1[2] = {floor(aHalfBisect)*2 + 1, floor(bHalfBisect)*2 + 1};
    float rect2[2];
    
    if (aHalfBisect - floor(aHalfBisect) < 0.5) 
        rect2[0] = rect1[0] - 1;
    else 
        rect2[0] = rect1[0] + 1;
    
    
    
    if (bHalfBisect - floor(bHalfBisect) < 0.5) 
        rect2[1] = rect1[1] - 1;
    else 
        rect2[1] = rect1[1] + 1;
     
    
    //rect1.inject(:*) + rect2.inject(:*);
	rect1[0]=rect1[0]*rect1[1];
	rect2[0]=rect2[0]*rect2[1];
	return FLOAT_TO_INT(rect1[0] + rect2[0]);
}


int main()
{
	int test[10][3]={{6,4,23},{30,2,65},{8,6,49},{16,20,333},{20,32,653},{30,26,795},{50,4,177},{2,2,5},{50,50,2521},{38,42,1563}};
	for (int i =0; i<10; i++)
printf("test %d, for rectangle %d x %d, should be %d and returns %d\n", i, test[i][0], test[i][1], test[i][2], solution(test[i][0], test[i][1]));
}
