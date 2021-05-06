/*Anthony Y. Encarnacion Torres #113862
 Jean Marco Ambert # 108124
 Jan Carlos Barreto Torres #127484*/
#include <iostream>
using namespace std;
#include "Inventory_Class.h"

int main()
{
	int itemNum, quantity;
	double cost, totalCost;
	Inventory item1;

	cout << "Enter item number: ";
	cin >> itemNum;
	cout << "\nEnter item quantity: ";
	cin >> quantity;
	cout << "\nEnter item cost: ";
	cin >> cost;
	cout << endl;

	item1.setItemNum(itemNum);
	item1.setQuantity(quantity);
	item1.setCost(cost);
	item1.display();
	return 0;
}

/*Enter item number: 456

Enter item quantity: 5

Enter item cost: 3.99

The item number is 456
The quantity is 5
The cost is 3.99
The total cost is 19.95*/
