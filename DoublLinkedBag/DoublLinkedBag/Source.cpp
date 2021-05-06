#include <iostream>
using namespace std;

#include "DoublyLinkedBag.h"

int main()
{
	DoublyLinkedBag<int> bag;

	bag.add(2);
	bag.display();
	bag.add(1);
	bag.display();
	bag.add(3);
	bag.display();
	bag.add(6);
	bag.display();
	bag.remove(3);
	bag.display();

	bag.reverse();
	bag.display();

	return 0;
}

/*Item count 1
Bag:
2

Inverse:
Item count 1
Bag:
2

Press any key to continue . . .
Item count 2
Bag:
1

Bag:
2

Inverse:
Item count 2
Bag:
2
Bag:
1

Press any key to continue . . .
Item count 3
Bag:
3

Bag:
1

Bag:
2

Inverse:
Item count 3
Bag:
2
Bag:
1
Bag:
3

Press any key to continue . . .
Item count 4
Bag:
6

Bag:
3

Bag:
1

Bag:
2

Inverse:
Item count 4
Bag:
2
Bag:
1
Bag:
3
Bag:
6

Press any key to continue . . .
Item count 3
Bag:
6

Bag:
1

Bag:
2

Inverse:
Item count 3
Bag:
2
Bag:
1
Bag:
6

Press any key to continue . . .
Item count 3
Bag:
2

Bag:
1

Bag:
6

Inverse:
Item count 3
Bag:
6
Bag:
1
Bag:
2

Press any key to continue . . .
*/