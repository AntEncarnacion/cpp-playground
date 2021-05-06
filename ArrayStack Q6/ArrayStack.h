//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT stack: Array-based implementation.
 Listing 7-1
 @file ArrayStack.h */
#pragma once
#include <cassert>       // For assert
#include <iostream>
#include "StackInterface.h"
using namespace std;
const int MAX_STACK = 15;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack
	
public:
	 ArrayStack();             // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
	 void display() const;
}; // end ArrayStack

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-1
	@file ArrayStack.cpp */

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;
	if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
	{
		top++;
		items[top] = newEntry;
		result = true;
	}  // end if

	return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	}  // end if

	return result;
}  // end pop


template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition

	// Stack is not empty; return top
	return items[top];
}  // end peek
// End of implementation file.


template<class ItemType>
void ArrayStack<ItemType>::display() const
{
	for (int i = 0; i < top +1; i++)
		cout << "Index " << i << ": " << items[i] << endl;
	cout << endl;
}