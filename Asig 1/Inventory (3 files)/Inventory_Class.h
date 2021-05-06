#pragma once
class Inventory
{
private:
	int itemNum;
	int quantity;
	double cost;
	double totalCost;
public:
	Inventory();
	Inventory(int, int, double);
	~Inventory();

	void setItemNum(int);
	void setQuantity(int);
	void setCost(double);
	int getItemNum() const;
	int getQuantity() const;
	double getCost() const;
	double getTotalCost() const;
	void display() const;
};