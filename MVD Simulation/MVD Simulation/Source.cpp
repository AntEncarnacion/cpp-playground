#include <iostream>
#include <string>
using namespace std;
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include "Customer.h"
#include "Event.h"

int currentTime = 0;
bool signinTellerAvailable = true;
bool paymentTellerAvailable = true;
bool licenseTellerAvailable = true;
bool regitrationTellerAvailable = true;
const int sTime = 10, licenseTime = 90, registerTime = 60, payTime = 30, checkTime = 10;

// Processes an arrival event. 
void processArrival(Event arrivalEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue)
{
    // Remove this event from the event list 
    eventListPQueue.remove();
    cout << arrivalEvent.getName() << " has entered the sign in line at time:" << arrivalEvent.getTime() << '\n';
    Customer customer(arrivalEvent);
    if (signinQueue.isEmpty() && signinTellerAvailable)
    {
        int signinTime = currentTime + sTime;
        Event newSigninEvent(arrivalEvent.getName(), 'S', signinTime, arrivalEvent.getPay(), customer.getChoice());
        eventListPQueue.add(newSigninEvent);
        signinTellerAvailable = false;

        /*
         int departureTime = currentTime + arrivalEvent.getLength();
         Event newDepartureEvent('D', departureTime, 0);
         eventListPQueue.add(newDepartureEvent);
         tellerAvailable = false;
        */
    }
    else
        signinQueue.enqueue(customer);
}

void processSignin(Event newEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue, SL_PriorityQueue<Customer>& licensePQueue, LinkedQueue<Customer>& registrationQueue, LinkedQueue<Customer>& paymentQueue)
{
    eventListPQueue.remove();
    Customer customer(newEvent);
    cout << newEvent.getName() << " has signed in at time:" << newEvent.getTime() << '\n';



    if (newEvent.getChoice() == 'R')
    {
        cout << newEvent.getName() << " has entered auto registrationl line at time:" << newEvent.getTime() << '\n';
        if (registrationQueue.isEmpty() && regitrationTellerAvailable)
        {
            int eventTime = currentTime + registerTime;
            Event newRegistrationEvent(customer.getName(), 'R', eventTime, customer.getPay(), customer.getChoice());
            eventListPQueue.add(newRegistrationEvent);
            regitrationTellerAvailable = false;

        }
        else
        {
            registrationQueue.enqueue(customer);
        }
    }
    else if (newEvent.getChoice() == 'L')
    {
        cout << newEvent.getName() << " has entered license renewal line at time:" << newEvent.getTime() << '\n';
        if (licensePQueue.isEmpty() && licenseTellerAvailable)
        {
            int eventTime = currentTime + licenseTime;
            Event newLicenseEvent(customer.getName(), 'L', eventTime, customer.getPay(), customer.getChoice());
            eventListPQueue.add(newLicenseEvent);
            licenseTellerAvailable = false;
        }
        else
        {
            licensePQueue.add(customer);
        }
    }
    if (!signinQueue.isEmpty())
    {
        int signinTime = currentTime + sTime;
        Event newSigninEvent(signinQueue.peekFront().getName(), 'S', signinTime, signinQueue.peekFront().getPay(), signinQueue.peekFront().getChoice());
        eventListPQueue.add(newSigninEvent);
        signinQueue.dequeue();
        signinTellerAvailable = false;
    }
    else
        signinTellerAvailable = true;

}
void processLicense(Event newEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue, SL_PriorityQueue<Customer>& licensePQueue, LinkedQueue<Customer>& registrationQueue, LinkedQueue<Customer>& paymentQueue)
{
    eventListPQueue.remove();
    Customer customer(newEvent);


    if (paymentQueue.isEmpty() && paymentTellerAvailable)
    {
        int eventTime = currentTime;
        Event newRegistrationEvent(customer.getName(), 'P', eventTime, customer.getPay(), customer.getChoice());
        eventListPQueue.add(newRegistrationEvent);
        paymentTellerAvailable = false;
        cout << newRegistrationEvent.getName() << " renewed their license at time:" << newRegistrationEvent.getTime() << '\n';

    }
    else
    {
        paymentQueue.enqueue(customer);
    }
    if (!licensePQueue.isEmpty())
    {
        int signinTime = currentTime + licenseTime;
        Event newLicenseEvent(licensePQueue.peek().getName(), 'L', signinTime, licensePQueue.peek().getPay(), licensePQueue.peek().getChoice());
        eventListPQueue.add(newLicenseEvent);
        licensePQueue.remove();
        licenseTellerAvailable = false;
    }
    else
        licenseTellerAvailable = true;

}
void processRegistration(Event newEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue, SL_PriorityQueue<Customer>& licensePQueue, LinkedQueue<Customer>& registrationQueue, LinkedQueue<Customer>& paymentQueue)
{
    eventListPQueue.remove();
    Customer customer(newEvent);


    if (paymentQueue.isEmpty() && paymentTellerAvailable)
    {
        int eventTime = currentTime;
        Event newRegistrationEvent(customer.getName(), 'P', eventTime, customer.getPay(), customer.getChoice());
        eventListPQueue.add(newRegistrationEvent);
        paymentTellerAvailable = false;
        cout << newRegistrationEvent.getName() << " registered their auto at time:" << newRegistrationEvent.getTime() << '\n';

    }
    else
    {
        paymentQueue.enqueue(customer);
    }
    if (!registrationQueue.isEmpty())
    {
        int newTime = registrationQueue.peekFront().getTime() + registerTime;
        Event newRegisterEvent(registrationQueue.peekFront().getName(), 'R', newTime, registrationQueue.peekFront().getPay(), registrationQueue.peekFront().getChoice());
        eventListPQueue.add(newRegisterEvent);
        registrationQueue.dequeue();
        regitrationTellerAvailable = false;
    }
    else
        regitrationTellerAvailable = true;

}
void processPayment(Event newEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue, SL_PriorityQueue<Customer>& licensePQueue, LinkedQueue<Customer>& registrationQueue, LinkedQueue<Customer>& paymentQueue)
{
    eventListPQueue.remove();
    Customer customer(newEvent);

    cout << newEvent.getName() << " has reached the cashier at time:" << newEvent.getTime() << '\n';
    if (newEvent.getPay() == '$')
    {
        int eventTime = currentTime + payTime;
        Event newDepartureEvent(customer.getName(), 'D', eventTime, customer.getPay(), customer.getChoice());
        eventListPQueue.add(newDepartureEvent);
        paymentTellerAvailable = true;
    }
    else
    {
        int eventTime = currentTime + checkTime;
        customer.setPay('$');
        Customer newPaymentEvent(customer.getName(), 'P', eventTime, customer.getPay(), customer.getChoice());
        paymentQueue.enqueue(newPaymentEvent);
        cout << newPaymentEvent.getName() << " needs to get his check processed: " << newPaymentEvent.getTime() << '\n';


        
        Event newRegisterEvent(paymentQueue.peekFront().getName(), 'P', paymentQueue.peekFront().getTime(), paymentQueue.peekFront().getPay(), paymentQueue.peekFront().getChoice());
        eventListPQueue.add(newRegisterEvent);
        paymentQueue.dequeue();
        paymentTellerAvailable = false;
    }
}
// Processes a departure event 
void processDeparture(Event newEvent, SL_PriorityQueue<Event>& eventListPQueue, LinkedQueue<Customer>& signinQueue, SL_PriorityQueue<Customer>& licensePQueue, LinkedQueue<Customer>& registrationQueue, LinkedQueue<Customer>& paymentQueue)
{
    // Remove this event from the event list 
    eventListPQueue.remove();
    cout << newEvent.getName() << " has departed at time: " << newEvent.getTime() << '\n';
    if (!paymentQueue.isEmpty())
    {
        // Customer at front of line begins transaction 
        Customer customer = paymentQueue.peekFront();
        int departureTime = currentTime;
        paymentQueue.dequeue();
        Event newDepartureEvent(customer.getName(), 'D', newEvent.getTime(), customer.getPay(), customer.getChoice());
        eventListPQueue.add(newDepartureEvent);
    }
    else
        paymentTellerAvailable = true;
}


// Performs the simulation.  
void simulate()
{
    LinkedQueue<Customer> signinQueue;
    LinkedQueue<Customer> registrationQueue;
    LinkedQueue<Customer> paymentQueue;
    SL_PriorityQueue<Customer> licensePQueue;
    SL_PriorityQueue<Event> eventListPQueue;

    string name;	// name of customer
    char type;	//	type of event: arrive, sign in, renew license, renew registration, and cope with the cashier. 
    int time;	//	arrival time in seconds
    char pay;	//	type of payment:  $  for cash,  C  for check

    int size = 0;
    cout << "Enter amount of events to be entered: ";
    cin >> size;

    // Create and add arrival events to event list  
    for (int i = 0; i < size; i++)
    {
        // Get next arrival time a and transaction time t from file
        cout << "Enter info: ";
        cin >> name >> type >> time >> pay;

        Event newArrivalEvent(name, 'A', time, pay, type);
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
            processArrival(newEvent, eventListPQueue, signinQueue);
        }
        else if (newEvent.getType() == 'S')
        {
            processSignin(newEvent, eventListPQueue, signinQueue, licensePQueue, registrationQueue, paymentQueue);
        }
        else if (newEvent.getType() == 'L')
        {
            processLicense(newEvent, eventListPQueue, signinQueue, licensePQueue, registrationQueue, paymentQueue);
        }
        else if (newEvent.getType() == 'R')
        {
            processRegistration(newEvent, eventListPQueue, signinQueue, licensePQueue, registrationQueue, paymentQueue);
        }
        else if (newEvent.getType() == 'P')
        {
            processPayment(newEvent, eventListPQueue, signinQueue, licensePQueue, registrationQueue, paymentQueue);
        }
        else
        {
            processDeparture(newEvent, eventListPQueue, signinQueue, licensePQueue, registrationQueue, paymentQueue);
        }
    }
}

/*
    Events:
    arrive, sign in, renew license, renew registration, and cope with the cashier, departure
*/

int main()
{
    simulate();

	return 0;
}

/*
Enter amount of events to be entered: 6
Enter info: Anthony R 100 $
Enter info: Andrew L 4 C
Enter info: Miguel R 1 C
Enter info: Josh L 80 $
Enter info: Jean L 5 $
Enter info: Cesar R 2 C

Miguel has entered the sign in line at time:1
Cesar has entered the sign in line at time:2
Andrew has entered the sign in line at time:4
Jean has entered the sign in line at time:5
Miguel has signed in at time:11
Miguel has entered auto registrationl line at time:11
Cesar has signed in at time:21
Cesar has entered auto registrationl line at time:21
Andrew has signed in at time:31
Andrew has entered license renewal line at time:31
Jean has signed in at time:41
Jean has entered license renewal line at time:41
Miguel registered their auto at time:71
Miguel has reached the cashier at time:71
Miguel needs to get his check processed: 81
Josh has entered the sign in line at time:80
Miguel has reached the cashier at time:81
Cesar registered their auto at time:81
Cesar has reached the cashier at time:81
Cesar needs to get his check processed: 91
Josh has signed in at time:90
Josh has entered license renewal line at time:90
Cesar has reached the cashier at time:91
Anthony has entered the sign in line at time:100
Anthony has signed in at time:110
Anthony has entered auto registrationl line at time:110
Miguel has departed at time: 111
Cesar has departed at time: 121
Andrew renewed their license at time:121
Andrew has reached the cashier at time:121
Andrew needs to get his check processed: 131
Andrew has reached the cashier at time:131
Andrew has departed at time: 161
Anthony registered their auto at time:170
Anthony has reached the cashier at time:170
Anthony has departed at time: 200
Josh renewed their license at time:211
Josh has reached the cashier at time:211
Josh has departed at time: 241
Jean renewed their license at time:301
Jean has reached the cashier at time:301
Jean has departed at time: 331
*/