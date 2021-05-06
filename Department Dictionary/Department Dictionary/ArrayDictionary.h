#pragma once
#include <iostream>
#include <string>
using namespace::std;
#include "DictionaryInterface.h"
#include "Entry.h"
//#include "PrecondViolatedExcep.h"

template <class KeyType, class ItemType, class ItemTypeQueue>
class ArrayDictionary : public DictionaryInterface<KeyType, ItemType, ItemTypeQueue>
{
private:
	static const int DEFAULT_CAPACITY = 21; // Small capacity to test for
											// a full dictionary
	Entry<KeyType, ItemType, ItemTypeQueue>* items; // Array of dictionary entries
	int itemCount;                   // Current count of dictionary items
	int maxItems;                    // Maximum capacity of the dictionary
	void destroyDictionary();
	int findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const;
public:
	ArrayDictionary();
	ArrayDictionary(int maxNumberOfEntries);
	ArrayDictionary(const ArrayDictionary<KeyType, ItemType, ItemTypeQueue>& dict);

	virtual ~ArrayDictionary();

	bool isEmpty() const;
	int getNumberOfItems() const;
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool enqueue(const KeyType& searchKey, const ItemTypeQueue& newItem)  const /*throw (PrecondViolatedExcep)*/;
	bool dequeue(const KeyType& searchKey)  const /*throw (PrecondViolatedExcep)*/;
	bool remove(const KeyType& searchKey, const ItemTypeQueue& newItem);
	void clear();
	ItemType getItem(const KeyType& searchKey) const /*throw (PrecondViolatedExcep)*/;
	bool contains(const KeyType& searchKey) const;
	bool containsItem(const KeyType& searchKey, const ItemTypeQueue& newItem);

	/** Traverses the items in this dictionary in sorted search-key order
		and calls a given client function once for each item. */
	void traverse(void visit(ItemType&)) const;
	void display()const;
	void displayUnemployed()const;

}; // end ArrayDictionary


template <class KeyType, class ItemType, class ItemTypeQueue >
ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::ArrayDictionary() :itemCount(0), maxItems(DEFAULT_CAPACITY)
{
	items = new Entry<KeyType, ItemType, ItemTypeQueue>[maxItems];


}

template <class KeyType, class ItemType, class ItemTypeQueue>
ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::ArrayDictionary(int maxNumberOfEntries) :itemCount(0), maxItems(maxNumberOfEntries)
{
	items = new Entry<KeyType, ItemType, ItemTypeQueue>[maxNumberOfEntries];
}

template <class KeyType, class ItemType, class ItemTypeQueue>
ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType, ItemTypeQueue>& dict) {}

template <class KeyType, class ItemType, class ItemTypeQueue>
ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::~ArrayDictionary() {
	//cout << "\n\nDESTROYING:\n\n";
	//for (int index = 0; index < getNumberOfItems(); index++) {
	//	cout << "index:" << index;
	//	while (!((items[index].getQueue())->isEmpty())) {
	//		cout << " " << (items[index].getQueue())->peekFront() << ",";
	//		(items[index].getQueue())->dequeue();
	//	}
	//	cout << endl;
	//}
	//system("pause");
	//delete[] items;
	//items = NULL;
}

template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::isEmpty() const {
	return (itemCount == 0);
}

template <class KeyType, class ItemType, class ItemTypeQueue>
int ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::getNumberOfItems()  const /*throw (PrecondViolatedExcep)*/
{
	return(itemCount);
}


template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::add(const KeyType& searchKey, const ItemType& newItem)
{

	bool ableToInsert = (itemCount < maxItems);

	if (ableToInsert)
	{
		// Make room for new entry by shifting all entries at
		// positions >= newPosition toward the end of the array
		// (no shift if newPosition == itemCount + 1). Performing
		// a binary search doesn’t help here, because we need to
		// shift the entries while looking for the insertion location.
		int index = itemCount;

		// Short-circuit evaluation is important
		while ((index > 0) && (searchKey < items[index - 1].getKey()))
		{
			items[index] = items[index - 1];
			index--;
		}  // end while

		// Insert new entry
		items[index] = Entry<KeyType, ItemType, ItemTypeQueue>(newItem, searchKey);
		itemCount++; // Increase count of entries
	}  // end if
	return ableToInsert;
}



template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::remove(const KeyType& searchKey, const ItemTypeQueue& newItem) 
{
	int index = findEntryIndex(0, getNumberOfItems(), searchKey);

	if (!items[index].getQueue()->isEmpty())
	{
		items[index].getQueue()->dequeue(newItem);

		return true;
	}
	return false;
}

template <class KeyType, class ItemType, class ItemTypeQueue>
void ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::clear() 
{
	itemCount = 0;
}


/** Retrieves an item with a given search key from a dictionary.
@post  If the retrieval is successful, the item is returned.
@param searchKey  The search key of the item to be retrieved.
@return  The item associated with the search key.
@throw  NotFoundException if the item does not exist. */
template <class KeyType, class ItemType, class ItemTypeQueue>
ItemType ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::getItem(const KeyType& searchKey) const /*throw (PrecondViolatedExcep)*/ 
{


	//if (isEmpty()) {
	//	//throw (PrecondViolatedExcep("El arreglo esta vacio "));

	//}
	//else {
		int index = findEntryIndex(0, getNumberOfItems(), searchKey);
		cout << index << endl;
		//if (index != -1) {
			return items[index].getItem();
		//}
		//else /*throw (PrecondViolatedExcep("En el arreglo no existe ese key"))*/;

	//}

}


template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::contains(const KeyType& searchKey) const 
{
	bool results = false;
	int index = 0;
	while (index < getNumberOfItems()) 
	{
		if (searchKey == items[index].getKey()) 
		{
			results = true;

		}//end if
		index++;
	}//end while
	return results;
}

/** Traverses the items in this dictionary in sorted search-key order
and calls a given client function once for each item. */

template <class KeyType, class ItemType, class ItemTypeQueue>
void ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::traverse(void visit(ItemType&)) const {}
template <class KeyType, class ItemType, class ItemTypeQueue>
void ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::destroyDictionary() {}
template <class KeyType, class ItemType, class ItemTypeQueue>
int ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const 
{
	int EntryIndex = -1;
	int index = firstIndex;
	while (index < lastIndex) {
		if (searchKey == items[index].getKey()) {
			EntryIndex = index;
		}//end if
		index++;
	}//end while
	return EntryIndex;
}

template <class KeyType, class ItemType, class ItemTypeQueue>
void ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::display()const 
{
	ListQueue<ItemTypeQueue >* current = nullptr;

	for (int index = 0; index < getNumberOfItems() - 1; index++) 
	{
		current = (items[index].getQueue());
		if (current != NULL) 
		{
			cout << items[index].getKey() << endl;
			current->display();
		}
	}
}

template <class KeyType, class ItemType, class ItemTypeQueue>
void ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::displayUnemployed()const
{
	int index = findEntryIndex(0, getNumberOfItems(), "Unemployed");
	ListQueue<ItemTypeQueue >* current = (items[index].getQueue());

			cout << items[index].getKey() << endl;
			current->displayUnemployed();

}



template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::enqueue(const KeyType& searchKey, const ItemTypeQueue& newItem)  const /*throw (PrecondViolatedExcep)*/ {
	bool ableToInsert = false;

	//if (isEmpty()) {
	//	//throw PrecondViolatedExcep("El arreglo esta vacio");
	//}
	//else {
		int index = findEntryIndex(0, getNumberOfItems(), searchKey);
		//cout << index << endl;
		if (index != -1) 
		{
			(items[index].getQueue())->enqueue(newItem);
			ableToInsert = true;
		}
		//else throw PrecondViolatedExcep("En el arreglo no existe ese key");
		return ableToInsert;
	//}
}


template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::dequeue(const KeyType& searchKey)  const/* throw (PrecondViolatedExcep)*/ {
	bool ableToInsert = false;
	ListQueue<ItemTypeQueue >* current = nullptr;
	if (isEmpty()) {
		//throw PrecondViolatedExcep("El arreglo esta vacio");
	}
	else {
		int index = findEntryIndex(0, getNumberOfItems(), searchKey);
		cout << index << endl;
		if (index != -1) {

			(items[index].getQueue())->dequeue();

			ableToInsert = true;
		}
		else /*throw PrecondViolatedExcep("En el arreglo no existe ese key")*/;
		return ableToInsert;
	}
}

template <class KeyType, class ItemType, class ItemTypeQueue>
bool ArrayDictionary<KeyType, ItemType, ItemTypeQueue>::containsItem(const KeyType& searchKey, const ItemTypeQueue& newItem)
{
	int index = findEntryIndex(0, getNumberOfItems(), searchKey);

	if (items[index].getQueue() != nullptr)
		return true;
	return false;


}