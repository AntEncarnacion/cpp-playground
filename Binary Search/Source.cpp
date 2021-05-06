#include <iostream>
using namespace std;



int binarySearch(const int anArray[], int first, int last, int target)
{
    int index;
    if (first > last)
        index = -1; // target not in original array 
    else
    { // If target is in anArray, 
      // anArray[ﬁrst] <= target <= anArray[last] 
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid; // target found at anArray[mid] 
        else if (target < anArray[mid])    // Point X 
            index = binarySearch(anArray, first, mid - 1, target);
        else
            // Point Y   
            index = binarySearch(anArray, mid + 1, last, target);
    } // end if 

    return  index;
}

int main() {
    const int anArray[] = {1, 5, 9, 12, 15, 21, 29, 31};

    cout << "a. " << binarySearch(anArray, 0, 7, 5) << endl
        << "b. " << binarySearch(anArray, 0, 7, 13) << endl
        << "c. " << binarySearch(anArray, 0, 7, 16) << endl;

    return 0;
}