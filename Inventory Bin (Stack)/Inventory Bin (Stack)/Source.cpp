#include <iostream>
using namespace std;
#include "InventoryBin.h"
#include "LinkedStack.h"

int main()
{
	LinkedStack<InventoryBin> stack;
	InventoryBin* bin = new InventoryBin;

	int choice = 0;

	while (choice != 3)
	{
		cout << "INVENTORY BIN MENU\n1. Add item to bin.\n2. Remove item from bin.\n3. Finish and display all items in bin.\nChoice: ";
		cin >> choice;
		InventoryBin* bin = new InventoryBin;
		switch (choice)
		{
			case 1:
				cin >> *bin;
				stack.push(*bin);
				break;
			case 2:
				cout << "Removed:\n" << stack.peek() << endl;
				stack.pop();
				break;
			case 3:
				cout << "Displaying bin:\n";
				stack.display();
				break;
			default:
				cout << "Invalid input. Try again." << endl;
				break;
		}
		delete bin;
		system("pause");
		//system("cls");
	}

	cout << "Exiting..." << endl;

	return 0;

}



/*
DISPLAY
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 1
Enter data

Serial Number: 123456
Manufacture date: 1/1/20
Lot Number: 23165
Press any key to continue . . .
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 1
Enter data

Serial Number: 64976413
Manufacture date: 2/2/20
Lot Number: 465312
Press any key to continue . . .
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 1
Enter data

Serial Number: 78956432
Manufacture date: 3/3/20
Lot Number: 56497651
Press any key to continue . . .
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 1
Enter data

Serial Number: 321647
Manufacture date: 4/4/20
Lot Number: 76444134
Press any key to continue . . .
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 2
Removed:
Serial number: 321647
Manufacture date: 4/4/20
Lot number: 76444134


Press any key to continue . . .
INVENTORY BIN MENU
1. Add item to bin.
2. Remove item from bin.
3. Finish and display all items in bin.
Choice: 3
Displaying bin:
Top: Serial number: 78956432
Manufacture date: 3/3/20
Lot number: 56497651


Serial number: 64976413
Manufacture date: 2/2/20
Lot number: 465312


Serial number: 123456
Manufacture date: 1/1/20
Lot number: 23165


Press any key to continue . . .
*/