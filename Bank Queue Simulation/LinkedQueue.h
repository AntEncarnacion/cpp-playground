#include <cassert>
using namespace std;
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
   LinkedQueue(const LinkedQueue& aQueue);
   ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
   
    Node<ItemType>* getFrontPtr() const;
    Node<ItemType>* getBacktPtr() const;
   /** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const;
    void display() const;
}; // end LinkedQueue

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : backPtr(nullptr), frontPtr(nullptr)
{
}
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{
    Node<ItemType>* curPtr = aQueue.getFrontPtr();

    while (curPtr != nullptr)
    {
        enqueue(curPtr->getItem());
        curPtr = curPtr->getNext();
    }
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    while (!isEmpty())
        dequeue();
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

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    return (frontPtr == nullptr);
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
    return frontPtr->getItem();
}

template<class ItemType>
Node<ItemType>* LinkedQueue<ItemType>::getFrontPtr() const
{
    return frontPtr;
}

template<class ItemType>
Node<ItemType>* LinkedQueue<ItemType>::getBacktPtr() const
{
    return backPtr;
}

template<class ItemType>
void LinkedQueue<ItemType>::display() const
{
    Node<ItemType>* curPtr = frontPtr;

    while (curPtr != nullptr)
    {
        cout << "Content:" << endl;
        cout << curPtr->getItem() << endl;
        curPtr = curPtr->getNext();
    }
    system("pause");
}