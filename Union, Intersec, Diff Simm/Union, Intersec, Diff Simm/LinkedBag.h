//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#include <cstddef>
#include <cstdlib>
#include <ctime>

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   LinkedBag(const ItemType* newArray, int size);
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   bool removeLast(const ItemType& anEntry);
   void removeRand();
   bool addLast(const ItemType& newEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;
   void display() const;
   ItemType& operator[](int index);

}; // end LinkedBag

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */


template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const ItemType* anArray, int size)
{
    if (size == 0)
        headPtr = nullptr;  // Original array is empty
    else
    {
        for (int i = size - 1; i >= 0; i--) //  Reverse for loop for storing array inside of the Bag in the same order.
        {
            // Add to beginning of chain: new node references rest of chain;
            // (headPtr is null if chain is empty)        
            Node<ItemType>* nextNodePtr = new Node<ItemType>();
            nextNodePtr->setItem(anArray[i]);
            nextNodePtr->setNext(headPtr);  // New node points to chain
         //   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

            headPtr = nextNodePtr;          // New node is now first node
            itemCount++;
        }
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty)        
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(headPtr);  // New node points to chain
 //   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

    headPtr = nextNodePtr;          // New node is now first node
    itemCount++;

    return true;
}  // end add

template <class ItemType>
bool LinkedBag<ItemType>::addLast(const ItemType& newEntry)
{
    Node<ItemType>* nextNodePtr = new Node<ItemType>();     
    Node<ItemType>* newEntryNodePtr = new Node<ItemType>();

    newEntryNodePtr->setItem(newEntry);             //  Assign new entry to a new node
    newEntryNodePtr->setNext(nullptr);  
    nextNodePtr = headPtr;                          //  Assign headPtr to the node we will cycle through

    while (nextNodePtr->getNext() != nullptr)
        nextNodePtr = nextNodePtr->getNext();       //  Cycle through o the end of the list

    nextNodePtr->setNext(newEntryNodePtr);          //  Add new Node to the end of the list
    itemCount++;   

    return true;
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
    vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }  // end while

    return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    } // end if

    return canRemoveItem;
}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::removeLast(const ItemType& anEntry)
{
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);

    nextNodePtr = headPtr;                          //  Assign headPtr to the node we will cycle through

    while (nextNodePtr->getNext() != nullptr)
        nextNodePtr = nextNodePtr->getNext();       //  Cycle through o the end of the list


    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(nextNodePtr->getItem());

        Node<ItemType>* nodeToDeletePtr = headPtr;

        while (nodeToDeletePtr->getNext() != nextNodePtr)
            nodeToDeletePtr = nodeToDeletePtr->getNext();       //  Cycle through o the end of the list

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);

        itemCount--;
    } // end if

    return canRemoveItem;
}  // end remove


template<class ItemType>
void LinkedBag<ItemType>::removeRand()
{
    if (headPtr != nullptr)
    {
        if (itemCount == 1)
        {
            Node<ItemType>* curPtr = headPtr;

            remove(curPtr->getItem());
        }
        else
        {
            Node<ItemType>* curPtr = headPtr;

            srand((unsigned)time(0));
            int randomNumber;
            for (int index = 0; index < 10; index++) {
                randomNumber = (rand() % itemCount);
            }
            int count = 0;

            while (count != randomNumber)
            {
                curPtr = curPtr->getNext();
                count++;
            }
            remove(curPtr->getItem());
        }
    }
}  // end rand remove


template<class ItemType>
void LinkedBag<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr

    itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
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
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;

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
void LinkedBag<ItemType>::display() const
{
    Node<ItemType>* curPtr = headPtr;

    cout << "Item count " << itemCount << endl;
    while (curPtr != nullptr)
    {
        cout << "Bag:" << endl;
        cout << curPtr->getItem() << endl;
        curPtr = curPtr->getNext();
    }
    system("pause");

}

template<class ItemType>
ItemType& LinkedBag<ItemType>::operator[](int index)
{
    Node<ItemType>* curPtr = headPtr;
    for (int i = 0; i < index; i++)
    {
        curPtr = curPtr->getNext();
    }
    return curPtr->getItem();
}