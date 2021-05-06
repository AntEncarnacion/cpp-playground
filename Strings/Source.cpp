//Notes on strings.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char cString[] = { 'H', 'i', ' ', 'g', 'u', 'y', 's', '\0' };		//This is a C string. Simply a char array with null at the end.
	sizeof(cString);													//This is how you get the total memory size of an array. And since every char is 1 byte of size. It equals to the amount of chars.

	vector<string> strVec(20);											//String Vector just for demostrating different string manipulation.

	string str("I'm a string");
	strVec[0] = str;

	str[0];																//Different ways to access the first character in a string.
	str.at(0);
	str.front();

	str.back();															//Easiest way to get the end of a string.

	str.length();														//Gets you the size of a string.

	string str2(str);													//Copies a string into another string.

	strVec[1] = str2;

	string str3(str, 4);												//Copies everything in string str after 4th character into str3.
	strVec[2] = str3;

	string str4(5, 'x');												//Copies the character 5 times into str4.
	strVec[3] = str4;

	strVec[4] = str.append(" and you're not");							//Two different ways of adding a new string at the end of the original one.
	str += " and you're not";

	str.append(str, 5, 3);												//Copies the string in first parameter into a new string. Second parameter is where it will start copying and third parameter is the amount of chars it will copy.
	strVec[5] = str;

	str.erase(13, str.length() - 1);									//Deletes everything starting at the index in first parameter and ending in the index in second parameter.
	strVec[6] = str;

	strVec[7] = str.substr(6, 6);										//Cuts a string on index in first parameter for the length of second parameter.
	
	reverse(str.begin(), str.end());									//Reverses a string
	strVec[8] = str;
	
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);		//From the algorithm library. It changes everything to lower case.
	strVec[10] = str2;
	
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);		//From the algorithm library. It changes everything to upper case.
	strVec[9] = str2;
	
	
	string secretStr = "";
	for(char c: str2)
        secretStr += std::to_string((int)c);
							//Turns every char in string into number form. a - z : 97 - 122. A - Z : 65 - 90.
	strVec[11] = secretStr;
	
	str2 = "";															//Turns upper case string from number format into char format. (Note: only works with two integer digit chars.)
	for (unsigned int i = 0; i < secretStr.length(); i += 2)
	{
		string sCharCode = "";
		sCharCode += secretStr[i];
		sCharCode += secretStr[i + 1];

		int nCharCode = stoi(sCharCode);								//String to int. Converts chars to int index number and it turns the numbers to their equal value in int.
		char chCharCode = nCharCode;
		str2 += chCharCode;
	}
	strVec[12] = str2;
	
	str2 = "String";
	secretStr = "";
	for(char c: str2)
        secretStr += std::to_string((int)c - 23);
							//Turns every char into a number format and substracts 23 to have it never be a 3 digit number.
	strVec[13] = secretStr;
	
	str2 = "";
	for (int i = 0; i < secretStr.length(); i += 2)						//Turns the number into a char. Only works with 2 digit numbers.
	{
		string sCharCode = "";
		sCharCode += secretStr[i];
		sCharCode += secretStr[i + 1];

		int nCharCode = stoi(sCharCode);
		char chCharCode = nCharCode + 23;								//Turns the double digit number into the original char.
		str2 += chCharCode;
	}
	strVec[14] = str2;
	
	
	
	for (auto x : strVec)
		cout << x << endl;

	if (str.find("string") != string::npos)								//Searches for keyword and returns the index of where the keyword starts.
		cout << str.find("string") << endl;
	


	return 0;
}