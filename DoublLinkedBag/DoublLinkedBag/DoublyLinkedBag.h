#pragma once
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file DoublyLinkedBag.h 
    Listing 4-3 */
#include <cstddef>
#include "BagInterface.h"
#include "DoublyNode.h"

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
   DoublyNode<ItemType>* headPtr; // Pointer to first DoublyNode
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the DoublyNode containing a given entry
   // or the null pointer if the entry is not in the bag.
   DoublyNode<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   DoublyLinkedBag();
   virtual ~DoublyLinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   void reverse();
   void display() const;
}; // end DoublyLinkedBag

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file DoublyLinkedBag.cpp */

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor


template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
    clear();
}  // end destructor

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Add to beginning of chain: new DoublyNode references rest of chain;
    // (headPtr is null if chain is empty)        
    DoublyNode<ItemType>* nextDoublyNodePtr = new DoublyNode<ItemType>();
    nextDoublyNodePtr->setItem(newEntry);
    nextDoublyNodePtr->setNext(headPtr);  // New DoublyNode points to chain
 //   DoublyNode<ItemType>* nextDoublyNodePtr = new DoublyNode<ItemType>(newEntry, headPtr); // alternate code

    headPtr = nextDoublyNodePtr;          // New DoublyNode is now first DoublyNode
    itemCount++;

    if (nextDoublyNodePtr->getNext() != nullptr)
    {
        DoublyNode<ItemType>* tempDoublyNode = new DoublyNode<ItemType>();
        tempDoublyNode = nextDoublyNodePtr->getNext();
        tempDoublyNode->setPrev(nextDoublyNodePtr);
    }

    return true;
}  // end add

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    DoublyNode<ItemType>* entryDoublyNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryDoublyNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first DoublyNode to located DoublyNode
        entryDoublyNodePtr->setItem(headPtr->getItem());

        // Delete first DoublyNode
        DoublyNode<ItemType>* DoublyNodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        DoublyNode<ItemType>* tempDoublyNode = headPtr;
        tempDoublyNode->setPrev(nullptr);

        // Return DoublyNode to the system
        DoublyNodeToDeletePtr->setNext(nullptr);
        delete DoublyNodeToDeletePtr;
        DoublyNodeToDeletePtr = nullptr;

        itemCount--;
    } // end if

    return canRemoveItem;
}  // end remove

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
    DoublyNode<ItemType>* DoublyNodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        // Return DoublyNode to the system
        DoublyNodeToDeletePtr->setNext(nullptr);
        delete DoublyNodeToDeletePtr;

        DoublyNodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; DoublyNodeToDeletePtr is nullptr

    itemCount = 0;
}  // end clear


template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    DoublyNode<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        } // end if

        counter++;
        curPtr = curPtr->getNext();
    } // end while

    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the DoublyNode containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
DoublyNode<ItemType>* DoublyLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    DoublyNode<ItemType>* curPtr = headPtr;

    while (!found && (curPtr != nullptr))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
} // end getPointerTo

template<class ItemType>
void DoublyLinkedBag<ItemType>::reverse()
{
    DoublyNode<ItemType>* firstDoublyNode = headPtr;
    DoublyNode<ItemType>* lastDoublyNode = headPtr;

    while (lastDoublyNode->getNext() != nullptr)
        lastDoublyNode = lastDoublyNode->getNext();

    if (itemCount % 2 != 0) //  Si el count es impar
    {
        while (firstDoublyNode != lastDoublyNode)
        {
            ItemType temp = firstDoublyNode->getItem();
            firstDoublyNode->setItem(lastDoublyNode->getItem());
            lastDoublyNode->setItem(temp);

            firstDoublyNode = firstDoublyNode->getNext();
            lastDoublyNode = lastDoublyNode->getPrev();
        }
    }
    else if (itemCount % 2 == 0)    // Si el count es impar
    {
        for (int i = 0; i < itemCount / 2; i++)
        {
            ItemType temp = firstDoublyNode->getItem();
            firstDoublyNode->setItem(lastDoublyNode->getItem());
            lastDoublyNode->setItem(temp);

            firstDoublyNode = firstDoublyNode->getNext();
            lastDoublyNode = lastDoublyNode->getPrev();

        }
    }
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::display() const
{
    DoublyNode<ItemType>* curPtr = headPtr;

    cout << "Item count " << itemCount << endl;
    while (curPtr != nullptr)
    {
        cout << "Bag:" << endl;
        cout << curPtr->getItem() << endl << endl;
        curPtr = curPtr->getNext();
    }



    curPtr = headPtr;
    while (curPtr->getNext() != nullptr)
        curPtr = curPtr->getNext();

    cout << "Inverse:\n";

    cout << "Item count " << itemCount << endl;
    while (curPtr != nullptr)
    {
        cout << "Bag:" << endl;
        cout << curPtr->getItem() << endl;
        curPtr = curPtr->getPrev();
    }
    cout << endl;
    system("pause");

}

