#include <iostream>
using namespace std;
#include "Inventory_Class.h"

Inventory::Inventory()
{
	itemNum = 0;
	quantity = 0;
	cost = 0;
}

Inventory::Inventory(int num, int qt, double c)
{
	num = itemNum;
	qt = quantity;
	c = cost;
}

Inventory::~Inventory() {

}

void Inventory::setItemNum(int num)
{
	if (num >= 0)
		itemNum = num;
	else
	{
		cout << "Invalid itemNum\n";
		exit(EXIT_FAILURE);
	}
}

void Inventory::setQuantity(int qt)
{
	if (qt >= 0)
		quantity = qt;
	else
	{
		cout << "Invalid quantity\n";
		exit(EXIT_FAILURE);
	}
}

void Inventory::setCost(double c)
{
	if (c >= 0)
		cost = c;
	else
	{
		cout << "Invalid cost\n";
		exit(EXIT_FAILURE);
	}
}
int Inventory::getItemNum() const
{
	return itemNum;
}

int Inventory::getQuantity() const
{
	return quantity;
}

double Inventory::getCost() const
{
	return cost;
}

double Inventory::getTotalCost() const
{
	return getQuantity() * getCost();
}

void Inventory::display() const
{
	cout << "The item number is " << getItemNum() << endl;
	cout << "The quantity is " << getQuantity() << endl;
	cout << "The cost is " << getCost() << endl;
	cout << "The total cost is " << getTotalCost() << endl;
}