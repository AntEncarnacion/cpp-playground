//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Circular array-based implementation.
 Listing 14-4.
 @file ArrayQueue.h */


#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"

const int MAX_QUEUE = 5;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
   ItemType items[MAX_QUEUE]; // Array of queue items
   int front;                 // Index to front of queue
   int back;                  // Index to back of queue
   int count;                 // Number of items currently in the queue
   
public:
   ArrayQueue();
   // Copy constructor and destructor supplied by compiler
   bool isEmpty() const;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();
   void display() const;

   /** @throw PrecondViolatedExcep if queue is empty. */
   ItemType peekFront() const throw(PrecondViolatedExcep);
   ItemType& operator[](int);
   bool checkElement(ItemType& item);
}; // end ArrayQueue
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Circular array-based implementation.
 Listing 14-5.
 @file ArrayQueue.cpp */

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(MAX_QUEUE - 1), count(0)
{
} // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return count == 0;
} // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    bool result = false;
    if (count < MAX_QUEUE)
    {
        // Queue has room for another item
        back = (back + 1) % MAX_QUEUE;
        items[back] = newEntry;
        count++;
        result = true;
    } // end if

    return result;
} // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
    bool result = false;
    if (!isEmpty())
    {
        front = (front + 1) % MAX_QUEUE;
        count--;
        result = true;
    } // end if

    return result;
} // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
    // Enforce precondition
    if (isEmpty())
        throw PrecondViolatedExcep("peekFront() called with empty queue");

    // Queue is not empty; return front
    return items[front];
} // end peekFront
// End of implementation file.

template<class ItemType>
ItemType& ArrayQueue<ItemType>::operator[](int index) 
{
    return items[index];
}

template<class ItemType>
bool ArrayQueue<ItemType>::checkElement(ItemType& item)
{
    for (int i = 0; i < count; i++)
        if (this->items[i] == item)
            return true;
    return false;
}

template<class ItemType>
void ArrayQueue<ItemType>::display() const
{
    if (count != 0)
        for (int i = front; i < count; i++)
            cout << items[i] << endl;
}