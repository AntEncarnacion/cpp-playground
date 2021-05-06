#include <iostream>
#include <string>

using namespace std;
#include "DoublyLinkedBag.h"

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
    ItemType tempArray[MAX_SIZE];  // Temporary array

    // Initialize the local indices to indicate the subarrays
    int first1 = first;            // Beginning of first subarray
    int last1 = mid;               // End of first subarray
    int first2 = mid + 1;          // Beginning of second subarray
    int last2 = last;              // End of second subarray

    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;            // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }  // end if
        index++;
    }  // end while

    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }  // end while

    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }  // end for

    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}  // end merge

template <class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint

        // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid);

        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last);

        // Merge the two halves
        merge(theArray, first, mid, last);
    }  // end if
}  // end mergeSort


int main()
{
    DoublyLinkedBag<double> bag;
    int size = 0;


    cout << " Size del arreglo\n";
    cin >> size;
    double* arr = nullptr;
    arr = new double[size];



    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese un valor\n";
        cin >> arr[i];

        cout << endl;
    }


    //  CIN PARA EL USUARIO ENTRAR SUS PROPIOS VALORES AL BAG. ESTA EN COMENTARIO PARA EVITAR QUE EL USUARIO ENTRE UN BAG QUE NO ESTE SORTED.


   /* int sizeBag = 0;
    cout << " Size del Bag\n";
    cin >> sizeBag;


    double temp = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese un valor para el bag\n";
        cin >> temp;
        bag.add(temp);
        cout << endl;
    }*/


    //  UTILIZAMOS VALORES PREDETERMINADOS DENTRO DEL BAG PARA ASEGURARNOS QUE EL BAG ESTE ORDENADO DE ANTEMANO
    bag.add(6);
    bag.add(4);
    bag.add(3);
    bag.add(2);

    mergeSort(arr, 0, size - 1);    // SORT PARA EL ARRAY
    bag.insertSorted(arr, size);    // FUNCION QUE LE DA L
    bag.display();

    return 0;

}

/*
 Size del arreglo
4
Ingrese un valor
4

Ingrese un valor
1

Ingrese un valor
9

Ingrese un valor
5

Item count 8
Bag:
1

Bag:
2

Bag:
3

Bag:
4

Bag:
4

Bag:
5

Bag:
6

Bag:
9

Inverse:
Item count 8
Bag:
9
Bag:
6
Bag:
5
Bag:
4
Bag:
4
Bag:
3
Bag:
2
Bag:
1

Press any key to continue . . .
*/
