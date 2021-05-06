//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Link-based implementation.
 Listing 14-3.
 @file LinkedQueue.h */
#include <cassert>

#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   Node<ItemType>* backPtr;
   Node<ItemType>* frontPtr;

public:
   LinkedQueue();
   LinkedQueue  (const LinkedQueue& aQueue);
   ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
   
   /** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcep);
}; // end LinkedQueue

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// PARITALLY COMPLETE.

/** @file LinkedQueue.cpp */
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{

}
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{

}
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    
}


template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    // Insert the new node
    if (isEmpty())
        frontPtr = newNodePtr;        // Insertion into empty queue
    else
        backPtr->setNext(newNodePtr); // Insertion into nonempty queue

    backPtr = newNodePtr;            // New node is at back

    return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    bool result = false;
    if (!isEmpty())
    {
        // Queue is not empty; delete front
        Node<ItemType>* nodeToDeletePtr = frontPtr;
        if (frontPtr == backPtr)
        {  // Special case: one node in queue
            frontPtr = nullptr;
            backPtr = nullptr;
        }
        else
            frontPtr = frontPtr->getNext();

        // Return deleted node to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        result = true;
    }  // end if

    return result;
}  // end dequeue

