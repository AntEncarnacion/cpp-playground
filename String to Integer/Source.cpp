#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {

	
	// Convert a string into an array
	std::string sSentence = "This is a random string";

	// Create a vector
	std::vector<std::string> vecsWords;

	// A stringstream object receives strings separated
	// by a space and then spits them out 1 by 1
	std::stringstream ss(sSentence);

	// Will temporarily hold each word in the string
	std::string sIndivStr;

	// Defines what separates the words
	char cSpace = ' ';

	// While there are more words to extract keep
	// executing
	// getline takes strings from a stream of words stored
	// in the stream and each time it finds a blanks space
	// it stores the word proceeding the space in sIndivStr
	while (getline(ss, sIndivStr, cSpace)) {

		// Put the string into a vector
		vecsWords.push_back(sIndivStr);
	}

	// Cycle through each index in the vector and print
	// out each word 
	for (auto x: vecsWords) {
		std::cout << x << "\n";
	}

	return 0;
}