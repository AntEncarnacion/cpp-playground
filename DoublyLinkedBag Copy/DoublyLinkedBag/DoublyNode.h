#pragma once
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file DoublyNode.h
    Listing 4-1 */
#include <cstddef>

template<class ItemType>
class DoublyNode
{
private:
    ItemType              item; // A data item
    DoublyNode<ItemType>* next; // Pointer to next DoublyNode
    DoublyNode<ItemType>* prev;

public:
    DoublyNode();
    DoublyNode(const ItemType& anItem);
    DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextDoublyNodePtr, DoublyNode<ItemType>* prevDoublyNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(DoublyNode<ItemType>* nextDoublyNodePtr);
    void setPrev(DoublyNode<ItemType>* prevDoublyNodePtr);
    ItemType getItem() const;
    DoublyNode<ItemType>* getNext() const;
    DoublyNode<ItemType>* getPrev() const;
}; // end DoublyNode


//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-4.





//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file DoublyNode.cpp
    Listing 4-2 */

template<class ItemType>
DoublyNode<ItemType>::DoublyNode() : next(nullptr), prev(nullptr)
{
} // end default constructor

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
} // end constructor

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextDoublyNodePtr, DoublyNode<ItemType>* prevDoublyNodePtr) :
    item(anItem), next(nextDoublyNodePtr), prev(prevDoublyNodePtr)
{
} // end constructor

template<class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
} // end setItem

template<class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* nextDoublyNodePtr)
{
    next = nextDoublyNodePtr;
} // end setNext

template<class ItemType>
void DoublyNode<ItemType>::setPrev(DoublyNode<ItemType>* prevDoublyNodePtr)
{
    prev = prevDoublyNodePtr;
} // end setNext

template<class ItemType>
ItemType DoublyNode<ItemType>::getItem() const
{
    return item;
} // end getItem

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const
{
    return next;
} // end getNext

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrev() const
{
    return prev;
}

