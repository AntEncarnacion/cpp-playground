//  Department Payroll Queue
#include <iostream>
#include <string>
using namespace std;
#include "ArrayQueue.h"


int main()
{
	ArrayQueue<int> queue1, queue2;

    queue1.enqueue(1);
    queue1.enqueue(2);
    queue2.enqueue(3);
    queue2.enqueue(4);
    queue1.dequeue();
    int queueFront = queue2.peekFront();
    queue1.enqueue(queueFront);
    queue1.enqueue(5);
    queue2.dequeue();
    queue2.enqueue(6);

    //queue1.display();
    //queue2.display();
    return 0;
}