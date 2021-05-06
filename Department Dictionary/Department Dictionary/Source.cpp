#include<iostream>
#include <string>

using namespace::std;
#include "ArrayDictionary.h"

int main() 
{
	ArrayDictionary<string, string, string> ArrayDepartment;
    string name, dept;
    bool validation = false;

    ArrayDepartment.add("IT", "IT");
    ArrayDepartment.add("Finance", "Finance");
    ArrayDepartment.add("Marketing", "Marketing");
    ArrayDepartment.add("Unemployed", "Unemployed");


    int choice = 0;
    while (choice != 5)
    {
        cout << "Menu:\n\n1. Join department.\n2. Quit department.\n3. Change department.\n4. Payroll.\n5.Exit.\n\nDepartments:\nIT\nMarketing\nFinance\n\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            //  Join <person> <department>
            cin.ignore();
            cout << "Enter name of person to be added: ";
            getline(cin, name);

            do {
                cin.ignore();
                cout << "Enter name of department the person will be added to:";
                getline(cin, dept);
                if (ArrayDepartment.contains(dept))
                    validation = true;
                else
                    cout << "Error, invalid department." << endl;
            } while (!validation);

            ArrayDepartment.enqueue(dept, name);

            if (ArrayDepartment.containsItem("Unemployed", name))
                ArrayDepartment.remove("Unemployed", name);

            break;
        case 2:
            ////  Quit <person>
            cin.ignore();

            cout << "Enter name of person to be removed: ";
            getline(cin, name);
            do {
                cin.ignore();
                cout << "Enter name of department the person will be removed to:";
                getline(cin, dept);
                if (ArrayDepartment.contains(dept))
                    validation = true;
                else
                    cout << "Error, invalid department." << endl;
            } while (!validation);

            ArrayDepartment.enqueue("Unemployed", name);
            ArrayDepartment.remove(dept, name);


            break;
        case 3:
            cin.ignore();

            cout << "Enter name of person to be removed: ";
            getline(cin, name);
            do {
                cin.ignore();
                cout << "Enter name of department the person will be removed to:";
                getline(cin, dept);
                if (ArrayDepartment.contains(dept))
                    validation = true;
                else
                    cout << "Error, invalid department." << endl;
            } while (!validation);

            ArrayDepartment.remove(dept, name);

            cin.ignore();
            cout << "Enter name of person to be added: ";
            getline(cin, name);

            do {
                cin.ignore();
                cout << "Enter name of department the person will be added to:";
                getline(cin, dept);
                if (ArrayDepartment.contains(dept))
                    validation = true;
                else
                    cout << "Error, invalid department." << endl;
            } while (!validation);

            ArrayDepartment.enqueue(dept, name);

            break;
        case 4:
            //  Payroll
            ArrayDepartment.display();
            ArrayDepartment.displayUnemployed();

            //for (int i = 0; i < 3; i++)
            //{
            //    cout << "Department " << i << ":" << endl;
            //    departmentList[i].displayPayroll();
            //}

            //if (!unemployedList.isEmpty())
            //{
            //    cout << "Unemployed list:" << endl;
            //    unemployedList.display();
            //}
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option try again..." << endl;
            break;
        }
        cin.ignore();
        //system("pause");
        //system("cls");
    }

 	//ArrayDepartment.display();

	//ArrayDepartment.enqueue("IT", "John");
	//ArrayDepartment.enqueue("Finance", "Ike");
	//ArrayDepartment.enqueue("Marketing", "Marth");
	//ArrayDepartment.enqueue("IT", "Joyner");
	//ArrayDepartment.enqueue("IT", "Lucas");
	//ArrayDepartment.display();
	//	ArrayDepartment.dequeue(4);
	//	ArrayDepartment.display();


	/*
	try
	{
		cout << ArrayDepartment.getItem(4) << endl;
	}

	catch (NotFoundException e)
	{
	}

	try
	{
		cout << ArrayDepartment.getItem(10) << endl;
	}

	catch (NotFoundException e)
	{

	}

	if (ArrayDepartment.contains(10)){
		cout << "si esta\n";
	}
	else{
		cout << "no esta\n";
	}

	*/
	system("pause");
	return 0;
}

/*
Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 1
Enter name of person to be added: Anthony

Enter name of department the person will be added to:IT

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 1
Enter name of person to be added: Jean

Enter name of department the person will be added to:IT

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 1
Enter name of person to be added: Michael

Enter name of department the person will be added to:IT

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 1
Enter name of person to be added: Talavera

Enter name of department the person will be added to:Marketing

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 4
Finance
IT
Anthony Pay: $3000
Jean Pay: $2000
Michael Pay: $1000
Marketing
Talavera Pay: $1000
Unemployed
Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 3
Enter name of person to be removed: Anthony

Enter name of department the person will be removed to:IT

Enter name of person to be added: Anthony

Enter name of department the person will be added to:Finance

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 2
Enter name of person to be removed: Jean

Enter name of department the person will be removed to:IT

Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 4
Finance
Anthony Pay: $1000
IT
Michael Pay: $1000
Marketing
Talavera Pay: $1000
Unemployed
Jean
Menu:

1. Join department.
2. Quit department.
3. Change department.
4. Payroll.
5.Exit.

Departments:
IT
Marketing
Finance

Choice: 5
Exiting...
Press any key to continue . . .
*/