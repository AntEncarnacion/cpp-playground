////using namespace std;
//#include <iostream>
//#include "LinkedBag.h"
//using namespace std;
//
//template<class ItemType>
//class SymmetricalD
//{
//public:
//    void SymmetricDifference(const int[], const int[], int, int);
//
//    void Difference(const int[], const int[], int, int);
//
//    void Intersection(const int[], const int[], int, int);
//
//    void Union(const int[], const int[], int, int);
//};
//
//template<class ItemType>
//void SymmetricalD<ItemType>::SymmetricDifference(const int  anArray1[], const int anArray2[], int size1, int size2)
//{
//    int* headP = new int[size1 + size2];
//    LinkedBag<ItemType> list1(anArray1, size1);
//    LinkedBag<ItemType> list2(anArray2, size2);
//
//    int count = 0;
//    int equal = 1;
//
//    int i = 0, j = 0;
//    while (i < size1 && j < size2)
//    {
//
//        if (list1[i] < list2[j])
//        {
//            headP[count++] = list1[i];
//            i++;
//        }
//        else if (list2[j] < list1[i])
//        {
//            headP[count++] = list2[j];
//            j++;
//        }
//
//        else
//        {
//            i++;
//            j++;
//        }
//
//
//    }
//
//    LinkedBag<ItemType> newList(headP, count);
//    newList.display();
//
//    for (int i = 0; i < list1.getCurrentSize(); i++)
//    {
//        for (int j = 0; j < list2.getCurrentSize(); j++)
//        {
//            if (list1[i] == list2[j])
//            {
//                equal = 1;
//                continue;
//            }
//        }
//        if (!equal)
//            headP[count++] = list1[i];
//        equal = 0;
//    }
//
//    LinkedBag<ItemType> newList(headP, count);
//    newList.display();
//
//}
//
//template<class ItemType>
//void SymmetricalD<ItemType>::Difference(const int  anArray1[], const int anArray2[], int size1, int size2)
//{
//
//    int* headP = new int[size1 + size2];
//    LinkedBag<ItemType> list1(anArray1, size1);
//    LinkedBag<ItemType> list2(anArray2, size2);
//
//
//    int* headP = new int[size1 + size2];
//    int count = 0;
//    int equal = 1;
//
//
//    for (int i = 0; i < list1.getCurrentSize(); i++)
//    {
//        for (int j = 0; j < list2.getCurrentSize(); j++)
//        {
//            if (list1[i] == list2[j])
//            {
//                equal = 1;
//                continue;
//            }
//        }
//        if (!equal)
//            headP[count++] = list1[i];
//        equal = 0;
//    }
//
//
//    LinkedBag<ItemType> newList(headP, count);
//    newList.display();
//
//    /*  int i = 0;
//      int j = 0;
//      while (i < size1 && j < size2)
//      {
//
//          if (list1[i] < list2[j])
//          {
//              cout << anArray1[i] << " ";
//              i++;
//          }
//          else if (list1[j] < list2[i])
//          {
//              cout << list2[j] << " ";
//              j++;
//          }
//          else
//          {
//              i++;
//              j++;
//          }
//      }*/
//      // LinkedBag<ItemType> newList(headP,count);
//       //newList.display();
//      //  return newList;
//
//}
//
//
//template<class ItemType>
//void SymmetricalD<ItemType>::Union(const int  anArray1[], const int anArray2[], int size1, int size2)
//{
//    LinkedBag<ItemType> list1(anArray1, size1);
//    LinkedBag<ItemType> list2(anArray2, size2);
//
//
//    int* headP = new int[size1 + size2];
//    int count = 0;
//    int equal = 1;
//
//    for (int i = 0; i < list1.getCurrentSize(); i++)
//    {
//        headP[count++] = list1[i];
//    }
//    for (int i = 0; i < list2.getCurrentSize(); i++)
//    {
//        for (int j = 0; j < list2.getCurrentSize(); j++)
//        {
//            if (list2[i] == list1[j])
//            {
//                equal = 1;
//                break;
//            }
//
//            else
//                equal = 0;
//        }
//        if (!equal)
//            headP[count++] = list2[i];
//        equal = 0;
//    }
//
//
//    LinkedBag<ItemType> newList(headP, count);
//    newList.display();
//    // newList.getCurrentSize() = count;
//    // for (int i = 0; i < count; i++)
//       //  newList[i] = headP[i];
//   //  return newList;
//
//
//
//         /*
//      LinkedBag<ItemType>   anArray11 =anArray1;
//      LinkedBag<ItemType>   anArray22 =anArray2;
//
//      LinkedBag <ItemType> anArray3 = nullptr;
//
//      cout << " Doing Union" << endl;
//      while (anArray11 != nullptr)
//      {
//
//              anArray3=add(anArray11->getItem());
//              anArray11 = anArray11->getNext();
//
//
//      }
//      while (anArray22 != nullptr)
//      {
//          if (!contains(anArray1))
//            anArray3=anArray22->getItem();
//
//            anArray22 = anArray22->getNext();
//
//
//      }
//      cout << " Union contains:\n";
//
//      while (anArray3 != nullptr)
//      {
//          cout << "Union:" << endl;
//          cout << anArray3->getItem() << endl;
//          anArray3 = anArray3->getNext();
//      }
//      system("pause");
//
//
//
//     // return anArray3;*/
//}
//
//template<class ItemType>
//void  SymmetricalD<ItemType>::Intersection(const int  anArray1[], const int anArray2[], int size1, int size2)
//{
//    LinkedBag<ItemType> list1(anArray1, size1);
//    LinkedBag<ItemType> list2(anArray2, size2);
//
//    int* headP = new int[size1 + size2];
//    int count = 0;
//    int equal = 1;
//
//    for (int i = 0; i < list1.getCurrentSize(); i++)
//    {
//        for (int j = 0; j < list2.getCurrentSize(); j++)
//        {
//            if (list1[i] == list2[j])
//            {
//                continue;
//            }
//
//            else
//                equal = 1;
//        }
//        if (equal)
//            headP[count++] = list1[i];
//        equal = 0;
//    }
//
//    LinkedBag<ItemType> newList(headP, count);
//    newList.display();
//    // newList.getCurrentSize() = count;
//    // for (int i = 0; i < count; i++)
//      //   newList[i] = headP[i];
//
//
//
//    /* LinkedBag<ItemType> anArray11 = anArray1;
//
//     Node<ItemType> * anArray3 = new Node<ItemType>();
//     anArray3 = nullptr;
//     LinkedBag<ItemType> anArray22 = anArray2;
//
//
//     while (anArray11 != nullptr)
//     {
//         if (!contains(anArray2))
//
//         anArray3=anArray1->getItem();
//         anArray1 = anArray1->getNext();
//
//     }
//
//     cout << " Interection contains:\n";
//
//     while (anArray3 != nullptr)
//     {
//         cout << "Intersection:" << endl;
//         cout << anArray3->getItem() << endl;
//         anArray3 = anArray3->getNext();
//     }
//     system("pause");
//
//
//
//   //  return anArray3;*/
//}