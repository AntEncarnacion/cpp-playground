//  Department Payroll Queue
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "ArrayQueue.h"

const int MAX_SIZE = 10;

int main()
{
	ArrayQueue<string>* departmentList;
    departmentList = new ArrayQueue<string>[MAX_SIZE];
    ArrayQueue<string> unemployedList;
    string name;
    int nameIndex, deptIndex;
    bool validation = false;

    int choice = 0;
    while (choice != 5)
    {
        cout << "Menu:\n\n1. Join department.\n2. Quit department.\n3. Change department.\n4. Payroll.\n5.Exit.\n\nDepartment Index:\n0 IT\n1 Customer Service\n2 Finances\n\nChoice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                //  Join <person> <department>
                cin.ignore();
                cout << "Enter name of person to be added: ";
                getline(cin, name);
               
                do {
                    cout << "Enter index of department [0-2] the person will be added to:";
                    cin >> deptIndex;
                    if (deptIndex >= 0 && deptIndex <= 2)
                        validation = true;
                    else
                        cout << "Error, invalid department." << endl;
                } while (!validation);

                departmentList[deptIndex].enqueue(name);

                if (unemployedList.checkElement(name))
                    unemployedList.remove(name);
                break;
            case 2:
                //  Quit <person>
                cin.ignore();

                cout << "Enter name of person to be removed: ";
                getline(cin, name);
                do{
                cout << "Enter index of department [0-2] the person will be removed from: ";
                cin >> deptIndex;
                if (deptIndex >= 0 && deptIndex <= 3)
                    validation = true;
                else
                    cout << "Error, invalid department." << endl;
                } while (!validation);

                departmentList[deptIndex].remove(name);
                unemployedList.enqueue(name);
                break;
            case 3:
                //  Change <person> <department>
                cin.ignore();

                cout << "Enter name of person to be changed: ";
                getline(cin, name);
                do {
                    cout << "Enter index of department [0-2] the person will be removed to:";
                    cin >> deptIndex;
                    if (deptIndex >= 0 && deptIndex <= 2)
                        validation = true;
                    else
                        cout << "Error, invalid department." << endl;
                } while (!validation);

                departmentList[deptIndex].remove(name);
                do {
                    cout << "Enter index of department [0-2] the person will be added from: ";
                    cin >> deptIndex;
                    if (deptIndex >= 0 && deptIndex <= 2)
                        validation = true;
                    else
                        cout << "Error, invalid department." << endl;
                } while (!validation);

                departmentList[deptIndex].enqueue(name);

                break;
            case 4:
                //  Payroll
                for (int i = 0; i < 3; i++)
                {
                    cout << "Department " << i << ":" << endl;
                    departmentList[i].displayPayroll();
                }

                if (!unemployedList.isEmpty())
                {
                    cout << "Unemployed list:" << endl;
                    unemployedList.display();
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option try again..." << endl;
                break;
        }
        cin.ignore();
        system("pause");
        system("cls");
    }


    delete[] departmentList;

    return 0;
}


/*1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Anthony
Enter index of department[0 - 2] the person will be added to : 0

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Juan
Enter index of department[0 - 2] the person will be added to : 0

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 2
Enter name of person to be removed : Juan
Enter index of department[0 - 2] the person will be removed from : 0

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Hob
Enter index of department[0 - 2] the person will be added to : 1

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Leon
Enter index of department[0 - 2] the person will be added to : 1

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 3
Enter name of person to be changed : Hob
Enter index of department[0 - 2] the person will be removed to : 1
Enter index of department[0 - 2] the person will be added from : 2

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Kyle
Enter index of department[0 - 2] the person will be added to : 1

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : John
Enter index of department[0 - 2] the person will be added to : 2

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 1
Enter name of person to be added : Claudia
Enter index of department[0 - 2] the person will be added to : 2

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.
Choice: 4
Department 0 :
    Anthony Pay : $1000

    Department 1 :
    Leon Pay : $2000
    Kyle Pay : $1000

    Department 2 :
    Hob Pay : $3000
    John Pay : $2000
    Claudia Pay : $1000

    Unemployed list :
Juan Pay : $0.00*/