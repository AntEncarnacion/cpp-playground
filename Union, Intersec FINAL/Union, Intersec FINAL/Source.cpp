#include <iostream>
using namespace std;
#include "LinkedBag.h"
#include "SymmetricDi.h"
/*void  Difference(LinkedBag<ItemType> &anArray1, LinkedBag<ItemType> &anArray2, int size1, int size2);
template<class ItemType>
void SymmetricDifference(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2, int size1, int size2);
template<class ItemType>
void Intersection(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2, int size1, int size2);
template<class ItemType>
void Union(LinkedBag<ItemType>& anArray1, LinkedBag<ItemType>& anArray2, int size1, int size2);
*/
int main()
{



    //  SymmetricalD<int> Symmetrical;

    const int anArray1[] = { 1,2,3,4,5 };
    const int anArray2[] = { 6,2,7,8,9 };

    int size1 = sizeof(anArray1) / sizeof(*anArray1);
    int size2 = sizeof(anArray2) / sizeof(*anArray2);


    int choice = 0;
    LinkedBag<int> list(anArray1, size1);
    LinkedBag<int> list2(anArray2, size2);

    SymmetricDi<int> sym1(list);
    SymmetricDi<int> sym2(list2);

    do {
        cout << " Choose Symmetrical Equation to do:\n (1) Union\n (2)Intersection\n (3)Difference\n (4)Symmetric Difference\n (0)Exit\n: ";
        cin >> choice;

        while (choice > 4 || choice < 0)
        {
            cout << " Invalid input please press a number between 1 to 4 to interact with the menu:";
            cin >> choice;
        }

        switch (choice)
        {

        case 0:
            return 0;
            break;
        case 1:
            //Symmetrical.
            sym1.Union(sym2);
            break;


        case 2:
            //Symmetrical.
            sym1.Intersection(sym2);
            break;

        case 3:
            //Symmetrical.
            sym1.Difference(sym2);
            break;

        case 4:
            //  Symmetrical.
            sym1.SymmetricDifference(sym2);
            break;

        }
    } while (choice < 4);



    return 0;
}