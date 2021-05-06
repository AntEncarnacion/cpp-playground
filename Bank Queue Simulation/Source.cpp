#include <iostream>
using namespace std;
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include "Event.h"

int currentTime = 0;
bool tellerAvailable = true;
int eventsCount = 0;
int totalArrivalTime = 0;
int totalDepartureTime = 0;
int totalProcessingTime = 0;
double averageWaitingTime;

// Processes an arrival event. 
void processArrival(Event& arrivalEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Event>& bankQueue)
{
    // Remove this event from the event list 
    eventListPQueue.remove();
    Event customer(arrivalEvent);
    if (bankQueue.isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + arrivalEvent.getLength();
        Event newDepartureEvent('D', departureTime, 0);
        eventListPQueue.add(newDepartureEvent);
        tellerAvailable = false;
    }
    else
        bankQueue.enqueue(customer);
    cout << "Processing an arrival event at time:\t" << customer.getTime() << endl;
    eventsCount++;
    totalArrivalTime += customer.getTime();
    totalProcessingTime += customer.getLength();
}

// Processes a departure event 
void processDeparture(Event departureEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Event>& bankQueue)
{
    // Remove this event from the event list 
    eventListPQueue.remove();
    if (!bankQueue.isEmpty())
    {
        // Event at front of line begins transaction 
        Event customer = bankQueue.peekFront();
        bankQueue.dequeue();
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departureTime, 0);
        eventListPQueue.add(newDepartureEvent);
    }
    else
        tellerAvailable = true;
    cout << "Processing a departure event at time:\t" << currentTime << endl;
    totalDepartureTime += currentTime;
}

// Performs the simulation.  
void simulate()
{
    LinkedQueue<Event> bankQueue;
    SL_PriorityQueue<Event> eventListPQueue;

    int arrivalTime = 0;
    int transTime = 0;

    int size = 0;
    cout << "Enter amount of events to be entered: ";
    cin >> size;

    // Create and add arrival events to event list  
    for (int i = 0; i < size; i++)
    {
        // Get next arrival time a and transaction time t from file
        cout << "Enter info: ";
        // Test case:
        //  
        cin >> arrivalTime >> transTime;

        Event newArrivalEvent('A', arrivalTime, transTime);
        eventListPQueue.add(newArrivalEvent);
    } // Event loop 

    while (!eventListPQueue.isEmpty())
    {
        Event newEvent = eventListPQueue.peek();
        // G et current time
        currentTime = newEvent.getTime();
        if (newEvent.getType() == 'A')
        {
            //cout << "A Event has arrived at time:" << newEvent.getTime() << '\n';
            processArrival(newEvent, eventListPQueue, bankQueue);
        }
        else
        {
            //cout << "A Event has departed at time: " << newEvent.getTime() << '\n';
            processDeparture(newEvent, eventListPQueue, bankQueue);
        }
    }
    averageWaitingTime = (double)(totalDepartureTime - totalProcessingTime - totalArrivalTime) / eventsCount;

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << eventsCount << endl;
    cout << "\tAverage amount of time spent waiting: " << averageWaitingTime << endl;
}

int main()
{
    simulate();

	return 0;
}