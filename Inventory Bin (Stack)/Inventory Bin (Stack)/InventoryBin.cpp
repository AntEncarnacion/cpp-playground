#include <iostream>
#include <string>
using namespace std;
#include "InventoryBin.h"

InventoryBin::InventoryBin() : serialNum(0), manufactDate(""), lotNum(0)
{
}
InventoryBin::InventoryBin(const InventoryBin& obj)
{
	serialNum = obj.getSerial();
	manufactDate = obj.getDate();
	lotNum = obj.getLot();
}
InventoryBin::InventoryBin(int serial, string date, int lot)
{
	serialNum = serial;
	manufactDate = date;
	lotNum = lot;
}
InventoryBin::~InventoryBin()
{
}
void InventoryBin::setSerial(int serial)
{
	serialNum = serial;
}
void InventoryBin::setDate(string date)
{
	manufactDate = date;
}
void InventoryBin::setLot(int lot)
{
	lotNum = lot;
}
int InventoryBin::getSerial() const
{
	return serialNum;
}
string InventoryBin::getDate() const
{
	return manufactDate;
}
int InventoryBin::getLot() const
{
	return lotNum;
}
void InventoryBin::display() const
{
	cout << "Serial number: " << serialNum << endl
		<< "Manufacture date: " << manufactDate << endl
		<< "Lot number: " << lotNum << endl << endl;
}

ostream& operator << (ostream& out, const InventoryBin& obj)
{
	out << "Serial number: " << obj.serialNum << endl
		<< "Manufacture date: " << obj.manufactDate << endl
		<< "Lot number: " << obj.lotNum << endl << endl;
	return out;
}
istream& operator >> (istream& in, InventoryBin& obj)
{
	cout << "Enter data\n\nSerial Number: ";
	in >> obj.serialNum;

	cin.ignore();
	cout << "Manufacture date: ";
	getline(cin, obj.manufactDate);

	cout << "Lot Number: ";
	in >> obj.lotNum;


	return in;
}