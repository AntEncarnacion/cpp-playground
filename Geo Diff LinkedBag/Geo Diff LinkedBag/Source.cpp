#include <iostream>
using namespace std;
#include "LinkedBag.h"
//void DiferenciaSim(int arr1[], int arr2[], int n, int m);
template<class ItemType>
void Intersection(LinkedBag<ItemType>&, LinkedBag<ItemType>&);
template<class ItemType>
LinkedBag<ItemType> Union(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2);

int main()
{


    const int anArray1[] = { 1,2,3,4,5 };
    const int anArray2[] = { 6,2,7,8,9 };


    int size1 = sizeof(anArray1) / sizeof(*anArray1);
    int size2 = sizeof(anArray2) / sizeof(*anArray2);


    LinkedBag<int> list(anArray1, size1);
    LinkedBag<int> list2(anArray2, size2);
    // Node<int> anArray1[] =  {1,2,3,4,5};
     //Node<int> anArray2[] = {6,2,7,8,9};



    /* anArray1.add(1);
     anArray1.add(2);
     anArray1.add(3);
     anArray1.add(4);
     anArray1.add(5);
     */
    Node<int>* union12 = nullptr;
    Node<int>* Intersec = nullptr;
    Node<int>* Difference = nullptr;




    /*
        anArray1.add(1);
         anArray1.add(2);
         anArray1.add(3);
         anArray1.add(4);
         anArray1.add(5);

         anArray2.add(6);
         anArray2.add(2);
         anArray2.add(7);
         anArray2.add(8);
         anArray2.add(9);
        */
        // DiferenciaSim(anArray1, anArray2, size1, size2);
    Union(list, list2);
    Intersection(list, list2);


    delete union12;
    union12 = nullptr;

    delete Intersec;
    Intersec = nullptr;

    system("pause");
    return 0;
}


/* template<class ItemType>
 void DiferenciaSim(const int anArray1[], const int anArray2[], int size1, int size2)
 {

     Node<ItemType> Array1 = ;


     int i = 0;
     int j = 0;
     while (i < size1 && j < size2)
     {

         if (anArray1[i] < anArray2[j])
         {
             cout << anArray1[i] << " ";
             i++;
         }
         else if (anArray1[j] <anArray2[i])
         {
             cout << anArray2[j] << " ";
             j++;
         }
         else
         {
             i++;
             j++;
         }
     }
 }*/


template<class ItemType>
LinkedBag<ItemType> Union(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2)
{

    ItemType* headP = new ItemType[anArray1.getCurrentSize() + anArray2.getCurrentSize()];
    int count = 0;
    int equal = 1;

    for (int i = 0; i < anArray1.getCurrentSize(); i++)
    {
        headP[count++] = anArray1[i];
    }
    for (int i = 0; i < anArray2.getCurrentSize(); i++)
    {
        for (int j = 0; j < anArray2.getCurrentSize(); j++)
        {
            if (anArray2[i] == anArray1[j])
            {
                equal = 1;
                break;
            }

            else
                equal = 0;
        }
        if (!equal)
            headP[count++] = anArray2[i];
        equal = 0;
    }


    LinkedBag<ItemType> ret(count);
    ret.getCurrentSize() = count;
    for (int i = 0; i < count; i++)
        ret[i] = headP[i];
    return ret;



    /*
 LinkedBag<ItemType>   anArray11 =anArray1;
 LinkedBag<ItemType>   anArray22 =anArray2;

 LinkedBag <ItemType> anArray3 = nullptr;

 cout << " Doing Union" << endl;
 while (anArray11 != nullptr)
 {

         anArray3=add(anArray11->getItem());
         anArray11 = anArray11->getNext();


 }
 while (anArray22 != nullptr)
 {
     if (!contains(anArray1))
       anArray3=anArray22->getItem();

       anArray22 = anArray22->getNext();


 }
 cout << " Union contains:\n";

 while (anArray3 != nullptr)
 {
     cout << "Union:" << endl;
     cout << anArray3->getItem() << endl;
     anArray3 = anArray3->getNext();
 }
 system("pause");



// return anArray3;*/
}

template<class ItemType>
LinkedBag<ItemType>  Intersection(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2)
{


    ItemType* headP = new ItemType[anArray1.getCurrentSize() + anArray2.getCurrentSize()];
    int count = 0;
    int equal = 1;

    for (int i = 0; i < anArray1.getCurrentSize(); i++)
    {
        for (int j = 0; j < anArray2.getCurrentSize(); j++)
        {
            if (anArray1[i] == anArray2[j])
            {
                continue;
            }

            else
                equal = 1;
        }
        if (equal)
            headP[count++] = anArray1[i];
        equal = 0;
    }


    LinkedBag<ItemType> ret(count);
    ret.getCurrentSize() = count;
    for (int i = 0; i < count; i++)
        ret[i] = headP[i];
    return ret;


    /* LinkedBag<ItemType> anArray11 = anArray1;

     Node<ItemType> * anArray3 = new Node<ItemType>();
     anArray3 = nullptr;
     LinkedBag<ItemType> anArray22 = anArray2;


     while (anArray11 != nullptr)
     {
         if (!contains(anArray2))

         anArray3=anArray1->getItem();
         anArray1 = anArray1->getNext();

     }

     cout << " Interection contains:\n";

     while (anArray3 != nullptr)
     {
         cout << "Intersection:" << endl;
         cout << anArray3->getItem() << endl;
         anArray3 = anArray3->getNext();
     }
     system("pause");



   //  return anArray3;*/
}