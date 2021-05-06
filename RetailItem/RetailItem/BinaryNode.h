//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 _Pearson Education_. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
//#include ""
//using namespace std;
#ifndef _BINARY_NODE
#define _BINARY_NODE

#include "RetailItem.h";

typedef char ItemType;

template<class ItemType>
class BinaryNode
{
private:
    ItemType              item;           // Data portion
    BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
    BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
    BinaryNode();
    BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem,BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;
    bool isChild() const;
    BinaryNode<ItemType>* getLeftChildPtr() const;
    BinaryNode<ItemType>* getRightChildPtr() const;

    void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
    void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
    
    
    BinaryNode<ItemType>& operator=(const RetailItem& rightHandSide)
    {

    
            rightHandSide.getDescription();

        //this = copyTree(&rightHandSide, rootPtr); // Call inherited method

        return *this;
    }  // end operator=
}; // end BinaryNode

template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
}// end constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) :item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}// end copy constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}// end constructor
/*
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,BinaryNode<ItemType>* rightPtr) : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}  // end constructor
*/

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
   // BinaryNode<ItemType>
    //if()
        
        return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    bool flag = false;
    if (leftChildPtr == nullptr && rightChildPtr == nullptr)
        flag = true;
    return flag;
}

template<class ItemType>
bool BinaryNode<ItemType>::isChild() const
{
    bool flag = false;
    if ((leftChildPtr != nullptr && rightChildPtr == nullptr) || (leftChildPtr == nullptr && rightChildPtr != nullptr))
        flag = true;
    return flag;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
    return(leftChildPtr);
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
    return (rightChildPtr);
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}
#endif