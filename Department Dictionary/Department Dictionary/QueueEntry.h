#pragma once
#include "Entry.h"
#include "ListQueue.h"


template<class KeyType, class ItemType>
class QueueEntry : public Entry<KeyType, ItemType>
{
private:
	ListQueue< ItemType>* queuePtr;

public:
	QueueEntry();
	QueueEntry(ItemType newEntry, KeyType searchKey);
	QueueEntry(ItemType newEntry, KeyType searchKey, QueueEntry<KeyType, ItemType>* nextEntryPtr);
	bool add(const KeyType& searchKey, const ItemType& newItem);
	//void setNext(QueueEntry<KeyType, ItemType>* nextEntryPtr);
//	QueueEntr<KeyType, ItemType>* getNext() const;
}; // end HashedEntry
template <class KeyType, class ItemType>
bool add(const KeyType& searchKey, const ItemType& newItem)
{
}
template <class KeyType, class ItemType>
QueueEntry<KeyType, ItemType>::QueueEntry() : Entry()
{
	queuePtr = new ListQueue< ItemType>();
}

template <class KeyType, class ItemType>
QueueEntry<KeyType, ItemType>::QueueEntry(ItemType newEntry, KeyType searchKey) : Entry(newEntry, searchKey)
{
	queuePtr = new ListQueue< ItemType>();
}

template <class KeyType, class ItemType>
QueueEntry<KeyType, ItemType>::QueueEntry(ItemType newEntry, KeyType searchKey, QueueEntry<KeyType, ItemType> *aQueuePtr) : Entry(newEntry, searchKey), queuePtr(aQueuePtr.queuePtr)
{
}
/*
template <class KeyType, class ItemType>
void QueueEntry<KeyType, ItemType>::setNext(QueueEntry<KeyType, ItemType>* nextEntryPtr){
	next = nextEntryPtr;
}

template <class KeyType, class ItemType>
QueueEntry<KeyType, ItemType>* QueueEntry<KeyType, ItemType>::getNext() const{
	return next;
}*/