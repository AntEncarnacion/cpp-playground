#pragma once
#include <iostream>
#include <string>
using namespace std;

class InventoryBin
{
private:
	int serialNum;
	string manufactDate;
	int lotNum;
public:
	InventoryBin();
	InventoryBin(const InventoryBin&);
	InventoryBin(int, string, int);
	~InventoryBin();
	void setSerial(int);
	void setDate(string);
	void setLot(int);
	int getSerial() const;
	string getDate() const;
	int getLot() const;
	void display() const;

	friend ostream& operator << (ostream&, const InventoryBin&);
	friend istream& operator >> (istream&, InventoryBin&);
};