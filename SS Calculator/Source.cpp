#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string sInput;
	double dNum1 = 0, dNum2 = 0;
	vector<string> vecBinomial;

	cout << "Enter a binomial with only constants: ";
	getline(cin, sInput);

	stringstream ss(sInput);
	string vecIndivS;
	char cSpace = ' ';

	while (getline(ss, vecIndivS, cSpace))
		vecBinomial.push_back(vecIndivS);

	dNum1 = stoi(vecBinomial[0]);
	dNum2 = stoi(vecBinomial[2]);
	string operation = vecBinomial[1];

	if (operation == "+")
		cout << dNum1 << " + " << dNum2 << " = " << (dNum1 + dNum2) << endl;
	else if (operation == "-")
		cout << dNum1 << " - " << dNum2 << " = " << (dNum1 - dNum2) << endl;
	else if (operation == "*")
		cout << dNum1 << " * " << dNum2 << " = " << (dNum1 * dNum2) << endl;
	else if (operation == "/")
		cout << dNum1 << " / " << dNum2 << " = " << (dNum1 / dNum2) << endl;
	else
		cout << "Invalid constant binomial..." << endl;

	return 0;
}