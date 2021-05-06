#include <iostream>

int main() {

	// An array is a collection of data of the same type
	// Declare an array of ints with the value of 1
	// Once the size is defined it can't change
	int arrnNums[10] = { 1 };

	// Leave out the array length
	int arrnNums2[] = { 1,2,3 };

	// Create an array and assign some values
	int arrnNums3[] = { 8, 9 };

	// Access array values using indexes starting with 0
	std::cout << "1st Value : " << arrnNums3[0] << "\n";

	// Change a value
	arrnNums3[0] = 7;
	std::cout << "1st Value : " << arrnNums3[0] << "\n";

	sizeof(arrnNums3);		// Get array size by getting the number of bytes
	sizeof(*arrnNums3);		// set aside for the array and then divide by the size
							// of the 1st element
	
	std::cout << "Array size : " << sizeof(arrnNums3) / sizeof(*arrnNums3) << "\n";


	// A multidimensional array is like a spreadsheet
	// If you think of each as layers that contain columns
	// 1st Number : Which layer
	// 2nd Number : Which column
	// 3rd Number : Which row
	int arrnNums4[2][2][2] = { {{1,2}, {3,4}},
	{{5,6}, {7,8}} };
	std::cout << arrnNums4[1][1][1] << "\n";

	return 0;
}