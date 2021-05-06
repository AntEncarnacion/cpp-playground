#pragma once
#pragma once
#include <iostream>
using namespace std;
#include "LinkedBag.h"
template <class ItemType>
class SymmetricDi 
{
private:
	LinkedBag<ItemType> listPtr;

public:
	SymmetricDi();
	SymmetricDi(LinkedBag<ItemType>);
	void Union(SymmetricDi<ItemType>&);
    void Difference(SymmetricDi<ItemType>&);
    void Intersection(SymmetricDi<ItemType>&);
    void SymmetricDifference(SymmetricDi<ItemType>&);
    SymmetricDi<ItemType>& operator=(const SymmetricDi<ItemType>&);
	LinkedBag<ItemType> getBag() const;
};

template <class ItemType>
SymmetricDi<ItemType>::SymmetricDi() 
{
}

template <class ItemType>
SymmetricDi<ItemType>::SymmetricDi(LinkedBag<ItemType> aBag)
{
    for (int i = 0; i < aBag.getCurrentSize(); i++)
        listPtr.add(aBag[i]);
    
}

template <class ItemType>
void SymmetricDi<ItemType>::Union(SymmetricDi<ItemType>& newPtr)
{
    LinkedBag<ItemType> list1(listPtr);
    LinkedBag<ItemType> list2(newPtr.getBag());
	int size1 = list1.getCurrentSize();
	int size2 = list2.getCurrentSize();

    int* headP = new int[size1 + size2];
    int count = 0;
    int equal = 1;

    for (int i = 0; i < list1.getCurrentSize(); i++)
    {
        headP[count++] = list1[i];
    }

    for (int i = 0; i < list2.getCurrentSize(); i++)
    {
        for (int j = 0; j < list2.getCurrentSize(); j++)
        {
            if (list2[i] == list1[j])
            {
                equal = 1;
                break;
            }

            else
                equal = 0;
        }
        if (!equal)
            headP[count++] = list2[i];
        equal = 0;
    }


    LinkedBag<ItemType> newList(headP, count);
    newList.display();
}

template<class ItemType>
void SymmetricDi<ItemType>::Difference(SymmetricDi<ItemType>& newPtr)
{
    LinkedBag<ItemType> list1(listPtr);
    LinkedBag<ItemType> list2(newPtr.getBag());
    int size1 = list1.getCurrentSize();
    int size2 = list2.getCurrentSize();


    int* headP = new int[size1 + size2];
    // LinkedBag<ItemType> list1(anArray1, size1);
    // LinkedBag<ItemType> list2(anArray2, size2);



    int count = 0;
    int equal = 1;


    for (int i = 0; i < list1.getCurrentSize(); i++)
    {
        for (int j = 0; j < list2.getCurrentSize(); j++)
        {
            if (list1[i] == list2[j])
            {
                equal = 1;
                continue;
            }
        }
        if (!equal)
            headP[count++] = list1[i];
        equal = 0;
    }


    LinkedBag<ItemType> newList(headP, count);
    newList.display();
}

template<class ItemType>
void SymmetricDi<ItemType>::Intersection(SymmetricDi<ItemType>& newPtr)
{
    LinkedBag<ItemType> list1(listPtr);
    LinkedBag<ItemType> list2(newPtr.getBag());
    int size1 = list1.getCurrentSize();
    int size2 = list2.getCurrentSize();

    // LinkedBag<ItemType> list1(anArray1, size1);
    // LinkedBag<ItemType> list2(anArray2, size2);

    int* headP = new int[size1 + size2];
    int count = 0;
    int equal = 0;

    for (int i = 0; i < list1.getCurrentSize(); i++)
    {
        for (int j = 0; j < list2.getCurrentSize(); j++)
        {
            if (list1[i] != list2[j])
            {
                continue;
            }
            else
                equal = 1;

        }
        if (equal)
            headP[count++] = list1[i];
        equal = 0;

    }


    LinkedBag<ItemType> newList(headP, count);
    newList.display();
}

template<class ItemType>
void SymmetricDi<ItemType>::SymmetricDifference(SymmetricDi<ItemType>& newPtr)
{
    LinkedBag<ItemType> list1(listPtr);
    LinkedBag<ItemType> list2(newPtr.getBag());
    int size1 = list1.getCurrentSize();
    int size2 = list2.getCurrentSize();

    int* headP = new int[size1 + size2];
    // LinkedBag<ItemType> list1(anArray1, size1);
     //LinkedBag<ItemType> list2(anArray2, size2);


    int count = 0;
    int equal = 1;

    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {

        if (list1[i] < list2[j])
        {
            headP[count++] = list1[i];
            i++;
        }
        else if (list2[j] < list1[i])
        {
            headP[count++] = list2[j];
            j++;
        }

        else
        {
            i++;
            j++;
        }


    }

    LinkedBag<ItemType> newList(headP, count);
    newList.display();


}


template <class ItemType>
SymmetricDi<ItemType>& SymmetricDi<ItemType>::operator=(const SymmetricDi<ItemType>& anArray2)
{
	listPtr = anArray2.getBag();
    return *this;
}


template <class ItemType>
LinkedBag<ItemType> SymmetricDi<ItemType>::getBag() const
{
	return listPtr;
}

