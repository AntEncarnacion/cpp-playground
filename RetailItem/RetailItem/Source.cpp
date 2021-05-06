
#include <iostream>
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "RetailItem.h"
using namespace std;



template<class T>
void display(T& anItem)
{
	cout << "Displaying: " << anItem << endl;
}

int main()
{
	RetailItem itemNew;
	RetailItem itemNew1;
	BinarySearchTree<RetailItem> itemSearch;
	BinaryNodeTree<RetailItem> itemNode;
//	BinaryNode<RetailItem> itemNode;
//	RetailItem itemToSearch;

	RetailItem item1=RetailItem("Jacket", 12, 59.95);
	RetailItem item2=RetailItem("Designer Jeans", 40, 34.95);
	RetailItem item3=RetailItem("Shirt", 20, 24.95);

	itemSearch.add(item1);
	itemSearch.add(item2);
	itemSearch.add(item3);


	string description ="";
	int unitsInHand=0;
	double price=0;

	string getDesc;

	int choice = 0;
	do {
	cout << "Menu:\n0. Add Item\n1. Delete item\n2.Search for item\n3. Update Inventory\n4. Display tree\n";
	cin >> choice;


		switch (choice)
		{
		case 0:
			//string newItem="";
			/*cout << "Input a new Item\n";
			string description;
			int unitsInHand;
			double price;*/
			
			cout << "Description of Item:\n";
			cin >> description;
			
			cout << "Units of Item:\n";
			cin >> unitsInHand;

			cout << "Price of Item:\n";
			cin >> price;
		
			itemNew.setDescription(description);
			itemNew.setUnitsOnHand(unitsInHand);
			itemNew.setPrice(price);

			itemSearch.add(itemNew);
			
			break;

		case 1:
	     cout <<"Input item to delete:\n";
			cin >> getDesc;
			itemNew1.setDescription(getDesc);
			//RetailItem itemToSearch;
			
			//bool test = itemSearch.search(itemto.getDescription());
			if (itemSearch.contains(itemNew1))
			{
				itemSearch.remove(itemNew1);
			}
			else
				cout << "Invalid input\n";
			break;
			
		case 2:
			
			/*cout << " Input the name of the item to search for" << endl;
			cin >> getDesc;
			//RetailItem itemToSearch;
			itemNew.setDescription(getDesc);

			//bool test = itemSearch.search(itemto.getDescription());
			if (itemSearch.contains(itemNew))
			{
				itemNew.displayItem(itemNew);
			}
			else
				cout << "Invalid input\n";*/
			break;

			
		case 3:
			
			/*cout << " Input item to edit:" << endl;
			cin >> getDesc;


			if (getDesc == itemNew.getDescription())
			{
				cout << "Description of Item:\n";
				cin >> description;

				cout << "Units of Item:\n";
				cin >> unitsInHand;

				cout << "Price of Item:\n";
				cin >> price;

				itemNew.setDescription(description);
				itemNew.setUnitsOnHand(unitsInHand);
				itemNew.setPrice(price);

				itemSearch.edit(itemNew);
			}
			else
				cout << "Invalid input\n";*/
			break;
		
		case 4:
			cout << "Items in retail:" << endl;
			itemSearch.inorderTraverse(display);
			break;

		}
	} while (choice < 5);

	system("pause");
	return 0;
}

