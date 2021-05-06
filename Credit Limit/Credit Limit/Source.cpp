#include<iostream>
using namespace std;

int main() {
	int accountNumber, choice = 0;
	float initBal, totalItems, totalCredits, creditLimit, newBal;

	while (choice != -1) {
		cout << "Welcome to credit limit check!\n";
		cout << "Enter account number: ";
		cin >> accountNumber;
		cout << "Enter Initial Balance: ";
		cin >> initBal;
		cout << "Enter total of all items: ";
		cin >> totalItems;
		cout << "Enter total of credits: ";
		cin >> totalCredits;
		cout << "Enter credit limit: ";
		cin >> creditLimit;

		newBal = initBal + totalItems - totalCredits;

		cout << "Account number is: " << accountNumber << endl
			<< "Credit Limit: " << creditLimit << endl
			<< "New Balance: " << newBal << endl;
		if (newBal >= creditLimit) 
			cout << "Credit limit exceeded!" << endl;
		cout << "Enter -1 to exit or any other number to continue: ";
		cin >> choice;
	}
	return 0;
}