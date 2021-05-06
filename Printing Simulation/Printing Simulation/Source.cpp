#include <iostream>
#include <string>
using namespace std;
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include "Event.h"

int currentTime = 0;
bool printer[3] = { true, true, true };

void processArrival(Event arrivalEvent, SL_PriorityQueue<Event>& eventListPQueue, SL_PriorityQueue<Event>& printingQueue, int printers)
{
    eventListPQueue.remove();
    Event customer(arrivalEvent);

    if (printers == 1)
    {
        if (printingQueue.isEmpty() && printer[0])
        {
            int departureTime = currentTime + arrivalEvent.getLength();
            Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 1);
            eventListPQueue.add(newDepartureEvent);
            printer[0] = false;
        }
        else
            printingQueue.add(customer);
    }

    else if (printers == 2)
    {
        if (printingQueue.isEmpty() && (printer[0] || printer[1]))
        {
            if (arrivalEvent.getPages() <= 10)
            {
                int departureTime = currentTime + arrivalEvent.getLength();
                Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 2);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0])
                    printer[0] = false;
                else
                    printer[1] = false;
            }
            else if (arrivalEvent.getPages() > 10 && (printer[0] && printer[1]))
            {
                int departureTime = currentTime + arrivalEvent.getLength();
                Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 2);
                eventListPQueue.add(newDepartureEvent);

                printer[0] = false;
                printer[1] = false;
            }
            else
                printingQueue.add(customer);
        }
        else
            printingQueue.add(customer);
    }
    else if (printers == 3)
    {
        if (printingQueue.isEmpty() && (printer[0] || printer[1] || printer[2]))
        {
            if (arrivalEvent.getPages() <= 10)
            {
                int departureTime = currentTime + arrivalEvent.getLength();
                Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0])
                    printer[0] = false;
                else if (printer[1])
                    printer[1] = false;
                else
                    printer[2] = false;
            }
            else if (arrivalEvent.getPages() <= 20 && ((printer[0] && printer[1]) || (printer[0] && printer[2]) || (printer[1] && printer[2])))
            {
                int departureTime = currentTime + arrivalEvent.getLength();
                Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0] && printer[1])
                { 
                    printer[0] = false;
                    printer[1] = false;
                }
                else if (printer[0] && printer[2])
                {
                    printer[0] = false;
                    printer[2] = false;
                }
                else if (printer[1] && printer[2])
                {
                    printer[1] = false;
                    printer[2] = false;
                }
            }
            else if (arrivalEvent.getPages() > 20 && printer[0] && printer[1] && printer[2])
            {
                int departureTime = currentTime + arrivalEvent.getLength();
                Event newDepartureEvent('P', arrivalEvent.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                printer[0] = false;
                printer[1] = false;
                printer[2] = false;
            }
            else
                printingQueue.add(customer);

        }
        else
            printingQueue.add(customer);

    }




    cout << "Processing an printing event at time:\t" << customer.getTime() << endl;

    //eventsCount++;
    //totalArrivalTime += customer.getTime();
    //totalProcessingTime += customer.getLength();
}

// Processes a departure event 
void processDeparture(Event departureEvent, SL_PriorityQueue<Event>& eventListPQueue, SL_PriorityQueue<Event>& printingQueue, int printers)
{
    eventListPQueue.remove();

    if (printers == 1)
    {
        if (!printingQueue.isEmpty())
        {
            Event customer = printingQueue.peek();
            printingQueue.remove();
            int departureTime = currentTime + customer.getLength();
            Event newDepartureEvent('P', customer.getPages(), departureTime, 1);
            eventListPQueue.add(newDepartureEvent);
        }
        else
            printer[0] = true;
    }
    else if (printers == 2)
    {
        if (!printingQueue.isEmpty())
        {

            if (departureEvent.getPages() <= 10)
            {
                Event customer = printingQueue.peek();
                printingQueue.remove();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('P', customer.getPages(), departureTime, 2);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0])
                    printer[0] = false;
                else
                    printer[1] = false;
            }
            else 
            {
                Event customer = printingQueue.peek();
                printingQueue.remove();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('P', customer.getPages(), departureTime, 2);
                eventListPQueue.add(newDepartureEvent);

                printer[0] = false;
                printer[1] = false;
            }
            


        }
        else
        {
            printer[0] = true;
            printer[1] = true;
        }
    }
    else if (printers == 3)
    {
        if (!printingQueue.isEmpty())
        {
            if (departureEvent.getPages() <= 10)
            {
                Event customer = printingQueue.peek();
                printingQueue.remove();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('P', customer.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0])
                    printer[0] = false;
                else if (printer[1])
                    printer[1] = false;
                else
                    printer[2] = false;
            }
            else if (departureEvent.getPages() <= 20 && ((printer[0] && printer[1]) || (printer[0] && printer[2]) || (printer[1] && printer[2])))
            {
                Event customer = printingQueue.peek();
                printingQueue.remove();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('P', customer.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                if (printer[0] && printer[1])
                {
                    printer[0] = false;
                    printer[1] = false;
                }
                else if (printer[0] && printer[2])
                {
                    printer[0] = false;
                    printer[2] = false;
                }
                else if (printer[1] && printer[2])
                {
                    printer[1] = false;
                    printer[2] = false;
                }
            }
            else 
            {
                Event customer = printingQueue.peek();
                printingQueue.remove();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('P', customer.getPages(), departureTime, 3);
                eventListPQueue.add(newDepartureEvent);

                printer[0] = false;
                printer[1] = false;
                printer[2] = false;
            }
            

        }
        else
        {
            printer[0] = true;
            printer[1] = true;
            printer[2] = true;
        }


    }



    cout << departureEvent.getPages() << " printed at time: " << departureEvent.getTime() << " with duration of: " << departureEvent.getLength() << endl;



    //// Remove this event from the event list 
    //eventListPQueue.remove();

    //if (!printingQueue.isEmpty())
    //{
    //    // Event at front of line begins transaction 
    //    Event customer = printingQueue.peek();
    //    printingQueue.remove();
    //    int departureTime = currentTime + customer.getLength();
    //    Event newDepartureEvent('P', customer.getPages(), departureTime, 1);
    //    eventListPQueue.add(newDepartureEvent);
    //}
    //else
    //    printer[0] = true;
    //cout << departureEvent.getPages() << " printed at time: " << departureEvent.getTime() << " with duration of: " << departureEvent.getLength() << endl;
    ////totalDepartureTime += currentTime;
}



// Performs the simulation.  
void simulate()
{
    SL_PriorityQueue<Event> eventListPQueue;
    SL_PriorityQueue<Event> printingQueue;

    int time;	//	arrival time in seconds
    int pages;  //  pages to be printed
    int printers = 0;
    int size = 0;

    cout << "Enter amount of events to be entered: ";
    cin >> size;
    cout << "Enter amount of printers to be used: ";
    cin >> printers;


    // Create and add arrival events to event list  
    for (int i = 0; i < size; i++)
    {
        // Get next arrival time a and transaction time t from file
        cout << "Enter info: ";
        cin >> pages >> time;

        Event newArrivalEvent('A', pages, time, 0);
        eventListPQueue.add(newArrivalEvent);
    } // Event loop 
    cout << '\n';

    while (!eventListPQueue.isEmpty())
    {
        Event newEvent = eventListPQueue.peek();
        // G et current time
        currentTime = newEvent.getTime();
        if (newEvent.getType() == 'A')
        {
            processArrival(newEvent, eventListPQueue, printingQueue, printers);
        }
        else
        {
            processDeparture(newEvent, eventListPQueue, printingQueue, printers);
        }
    }
}


int main()
{
    simulate();

    return 0;
}

/*
Enter amount of events to be entered: 5
Enter amount of printers to be used: 1
Enter info: 10 1
Enter info: 20 2
Enter info: 30 3
Enter info: 10 2
Enter info: 40 5

Processing an printing event at time:   1
Processing an printing event at time:   2
Processing an printing event at time:   2
Processing an printing event at time:   3
Processing an printing event at time:   5
10 printed at time: 61 with duration of: 60
20 printed at time: 121 with duration of: 120
10 printed at time: 181 with duration of: 60
30 printed at time: 241 with duration of: 180
40 printed at time: 321 with duration of: 240

Enter amount of events to be entered: 5
Enter amount of printers to be used: 2
Enter info: 10 1
Enter info: 30 2
Enter info: 20 3
Enter info: 10 4
Enter info: 20 5

Processing an printing event at time:   1
Processing an printing event at time:   2
Processing an printing event at time:   3
Processing an printing event at time:   4
Processing an printing event at time:   5
10 printed at time: 61 with duration of: 60
30 printed at time: 121 with duration of: 90
20 printed at time: 181 with duration of: 60
10 printed at time: 241 with duration of: 60
20 printed at time: 301 with duration of: 60

Enter amount of events to be entered: 5
Enter amount of printers to be used: 3
Enter info: 10 1
Enter info: 20 2
Enter info: 20 2
Enter info: 10 3
Enter info: 30 4

Processing an printing event at time:   1
Processing an printing event at time:   2
Processing an printing event at time:   2
Processing an printing event at time:   3
Processing an printing event at time:   4
10 printed at time: 61 with duration of: 60
20 printed at time: 62 with duration of: 60
20 printed at time: 121 with duration of: 60
10 printed at time: 122 with duration of: 60
30 printed at time: 181 with duration of: 60
*/
