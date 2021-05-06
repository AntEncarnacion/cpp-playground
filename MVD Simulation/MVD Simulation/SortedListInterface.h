#pragma once
#include <cassert>

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SortedListInterface
{

public:
    virtual void insertSorted(const ItemType& newEntry) = 0;
    virtual void removeSorted(const ItemType& anEntry) = 0;
    virtual int getPosition(const ItemType& newEntry) const = 0;

    // The following methods are the same as given in ListInterface:
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual ItemType getEntry(int position) const = 0;
}; // end LinkedSortedList

