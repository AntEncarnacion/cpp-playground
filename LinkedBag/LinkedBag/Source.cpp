#include <iostream>
using namespace std;
#include "LinkedBag.h"

    int main()
    {
        const int anArray[]{ 1, 2, 3, 4, 5 };
        int size = sizeof(anArray) / sizeof(*anArray);

        LinkedBag<int> list(anArray, size);

        list.removeLast(3);
        list.addLast(6);
        list.removeRand();
        list.display();
        system("PAUSE");


        LinkedBag<int> list2(list);

        list2.display();

        return 0;
    }

    /*
Item count 4
Bag:
2
Bag:
5
Bag:
1
Bag:
6
Press any key to continue . . .
Item count 4
Bag:
2
Bag:
5
Bag:
1
Bag:
6
Press any key to continue . . .
*/