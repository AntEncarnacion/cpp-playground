
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class RetailItem  //: public BinarySearchTree<ItemType> 
{
private:
    string description;  // Item description
    int unitsOnHand;     // Units on hand
    double price;        // Item price

public:

    RetailItem()
    {
    unitsOnHand = 0;
    description = "";
    price = 0;

    }

    // Constructor
    RetailItem(string d,int u,double p)
    {
        description = d; 
        unitsOnHand = u; 
        price = p;
    }


   ~RetailItem()
   {}

    // Mutators
    void setDescription(string d)
    {
        description = d;
    }

    void setUnitsOnHand(int u)
    {
        unitsOnHand = u;
    }

    void setPrice(double p)
    {
        price = p;
    }

    // Accessors
    string getDescription() const
    {
        return description;
    }

    int getUnitsOnHand() const
    {
        return unitsOnHand;
    }

    double getPrice() const
    {
        return price;
    }

    bool operator==(const RetailItem& rightHandSide)
    {
        bool flag = false;
           
        if (rightHandSide.getDescription()[0] == description[0])
            return true;
        
       else
        return flag;
    }  // end operator=


    bool operator>(const RetailItem& rightHandSide)
    {
        bool flag = false;

        if (rightHandSide.getDescription()[0] > description[0])
            return true;

        else
            return flag;
    }  // end operator=


    friend ostream& operator<<(ostream& leftItem, const RetailItem itemNew )
    {
        leftItem << setprecision(2) << fixed << showpoint;
        leftItem << "Description: " << itemNew.getDescription() << endl;
        cout << "Units on hand: " << itemNew.getUnitsOnHand() << endl;
        cout << "Price: $" << itemNew.getPrice() << endl << endl;
    
        return leftItem;
    }

    void displayItem(RetailItem item)
    {
        cout << setprecision(2) << fixed << showpoint;
        cout << "Description: " << item.getDescription() << endl;
        cout << "Units on hand: " << item.getUnitsOnHand() << endl;
        cout << "Price: $" << item.getPrice() << endl << endl;
    }
};
/*
// Function prototype
void displayItem(RetailItem);

int main()
{
    // Create three RetailItem objects.
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    // Display each item's data.
    displayItem(item1);
    displayItem(item2);
    displayItem(item3);

    return 0;
}*/

