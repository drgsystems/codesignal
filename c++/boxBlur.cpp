#include <iostream>
#include <vector>

using namespace std;

/*

Last night you partied a little too hard. Now there's 
a black and white photo of you that's about to go viral! 
You can't let this ruin your reputation, so you want to 
apply the box blur algorithm to the photo to hide its content.

The pixels in the input image are represented as INTEGERS. 
The algorithm distorts the input image in the following way: 
Every pixel x in the output image has a value equal to the 
average value of the pixel values from the 3 × 3 square that 
has its center at x, including x itself. All the pixels on the 
border of x are then removed.

Return the blurred image as an integer, with the fractions rounded down.

Example

For

image = [[1, 1, 1], 
         [1, 7, 1], 
         [1, 1, 1]]

the output should be solution(image) = [[1]].

To get the value of the middle pixel in the input 3 × 3 
square: (1 + 1 + 1 + 1 + 7 + 1 + 1 + 1 + 1) = 15 / 9 = 1.66666 = 1. 
The border pixels are cropped from the final result.

For

image = [[7, 4, 0, 1], 
         [5, 6, 2, 2], 
         [6, 10, 7, 8], 
         [1, 4, 2, 0]]

the output should be

solution(image) = [[5, 4], 
                  [4, 4]]

There are four 3 × 3 squares in the input image, so 
there should be four integers in the blurred output. 
To get the first value: 
(7 + 4 + 0 + 5 + 6 + 2 + 6 + 10 + 7) = 47 / 9 = 5.2222 = 5. 
The other three integers are obtained the same way, then 
the surrounding integers are cropped from the final result.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.array.integer image

    An image, stored as a rectangular matrix of non-negative integers.

    Guaranteed constraints:
    3 ≤ image.length ≤ 100,
    3 ≤ image[0].length ≤ 100,
    0 ≤ image[i][j] ≤ 255.

    [output] array.array.integer

    A blurred image represented as integers, obtained through the 
	process in the description.

*/
void printVector(vector<vector<int>> const &mat) {
    for (vector<int> row: mat)
    {
        for (int val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> solution(vector<vector<int>> image) {
	int i=0, j=0, k=0, l=0, row_size=image.size()-3+1;
	int col_size=image[0].size()-3+1;
	cout << "array_size=" << row_size << "x" << col_size << endl;
	vector<vector<int>> result(row_size,vector<int>(col_size,0));

	i=0;
	for(k=0; k < row_size; k++){
		for(l=0; l < col_size; l++){
			result[k][l]=(image[k][l]+image[k][l+1]+image[k][l+2]+
						 image[k+1][l]+image[k+1][l+1]+image[k+1][l+2]+
						 image[k+2][l]+image[k+2][l+1]+image[k+2][l+2])/9;
			cout << image[k][l] << " " << image[k][l+1] << " " << image[k][l+2] << endl;
			cout << image[k+1][l] << " " << image[k+1][l+1] << " " << image[k+1][l+2] << endl;
			cout << image[k+2][l] << " " << image[k+2][l+1] << " " << image[k+2][l+2] << endl;
			cout << "result[" << k << "][" << l << "]=" << result[k][l] << endl;
		}
		
	}

	return result;
}

int main()
{
	vector<vector<int>> test1={
		{7, 4, 0, 1}, 
         {5, 6, 2, 2}, 
         {6, 10, 7, 8}, 
		{1, 4, 2, 0}};
		 
	vector<vector<int>> test2={
		{1, 1, 1}, 
         {1, 7, 1}, 
		{1, 1, 1}};

	vector<vector<int>> test3={
		{36,0,18,9}, 
		{27,54,9,0}, 
		{81,63,72,45}};

	vector<vector<int>> result1(test1.size());

	cout << "array to blur = \n"; printVector(test1);
	cout << "array size test1=" << test2.size() << endl;
	result1=solution(test1);
	cout << "array after blur = \n"; printVector(result1);
	
	vector<vector<int>> result2(test2.size());

	cout << "array to blur = \n"; printVector(test2);
	cout << "array size test2=" << test2.size() << endl;
	result2=solution(test2);
	cout << "array after blur = \n"; printVector(result2);
	
	vector<vector<int>> result3(test3.size());

	cout << "array to blur = \n"; printVector(test3);
	cout << "array size test3=" << test3.size() << endl;
	result3=solution(test3);
	cout << "array after blur = \n"; printVector(result3);
}
