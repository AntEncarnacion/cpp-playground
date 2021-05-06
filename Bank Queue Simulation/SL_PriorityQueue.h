#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
   LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
                                          // items in the priority queue
public:
   SL_PriorityQueue();
   SL_PriorityQueue(const SL_PriorityQueue& pq);
   ~SL_PriorityQueue();

   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove();

   /** @throw PrecondViolatedExcep if priority queue is empty. */
   ItemType peek() const;
   void display() const;
}; // end SL_PriorityQueue

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() 
{
    slistPtr = new LinkedSortedList<ItemType>();
}

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
    slistPtr = new LinkedSortedList<ItemType>(pq);
}

template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
    while (!isEmpty())
        remove();
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
    slistPtr->insertSorted(newEntry);

    return true;
}  // end add

template<class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
    // The highest priority item is at the end of the sorted list
    return slistPtr->remove(1);
}  // end remove

template<class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
    return slistPtr->isEmpty();
}

template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peek() const
{
    return slistPtr->getEntry(1);
}

template<class ItemType>
void SL_PriorityQueue<ItemType>::display() const
{
    slistPtr->display();
}