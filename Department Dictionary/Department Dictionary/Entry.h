#pragma once
#include <iostream>
using namespace::std;

#include "ListQueue.h"
template <class KeyType, class ItemType, class ItemTypeQueue>
class Entry
{
private:
    ItemType item;
    KeyType searchKey;
    ListQueue< ItemTypeQueue>* queuePtr;

protected:
    void setKey(const KeyType& searchKey);

public:
    Entry();
    Entry(ItemType newEntry, KeyType searchKey);
    Entry(KeyType searchKey, ListQueue< ItemTypeQueue>* aQueue);
    ItemType getItem() const;
    KeyType getKey() const;
    void setItem(const ItemType& newEntry);
    bool operator==(const Entry<KeyType, ItemType, ItemTypeQueue>& rightHandItem) const;
    bool operator>(const Entry<KeyType, ItemType, ItemTypeQueue>& rightHandItem) const;
    ListQueue< ItemTypeQueue>* getQueue() const;
}; // end Entry

template <class KeyType, class ItemType, class  ItemTypeQueue>
Entry<KeyType, ItemType, ItemTypeQueue>::Entry()
{
    queuePtr = new 	ListQueue< ItemTypeQueue>();
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
Entry<KeyType, ItemType, ItemTypeQueue>::Entry(ItemType newEntry, KeyType itemKey)
{
    item = newEntry;
    searchKey = itemKey;
    queuePtr = new 	ListQueue< ItemTypeQueue>();
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
Entry<KeyType, ItemType, ItemTypeQueue>::Entry(KeyType itemKey, ListQueue< ItemTypeQueue>* aQueue) : searchKey(itemKey), queuePtr(aQueue.queuePtr)
{
    //queuePtr = new 	ListQueue< ItemTypeQueue>();
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
ItemType Entry<KeyType, ItemType, ItemTypeQueue>::getItem() const
{
    return item;
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
KeyType Entry<KeyType, ItemType, ItemTypeQueue>::getKey() const
{
    return searchKey;
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
ListQueue<ItemTypeQueue>* Entry<KeyType, ItemType, ItemTypeQueue>::getQueue() const
{
    return queuePtr;
}


template <class KeyType, class ItemType, class  ItemTypeQueue>
void Entry<KeyType, ItemType, ItemTypeQueue>::setItem(const ItemType& newEntry)
{
    item = newEntry;
}

template <class KeyType, class ItemType, class  ItemTypeQueue>
void Entry<KeyType, ItemType, ItemTypeQueue>::setKey(const KeyType& itemKey)
{
    searchKey = itemKey;
}
template <class KeyType, class ItemType, class  ItemTypeQueue>
bool Entry<KeyType, ItemType, ItemTypeQueue>::operator==(const Entry<KeyType, ItemType, ItemTypeQueue>& rightHandItem) const
{
    return (searchKey == rightHandItem.getKey());
} // end operator==


template <class KeyType, class ItemType, class  ItemTypeQueue>
bool Entry<KeyType, ItemType, ItemTypeQueue>::operator>(const Entry<KeyType, ItemType, ItemTypeQueue>& rightHandItem)
const
{
    return (searchKey > rightHandItem.getKey());
}