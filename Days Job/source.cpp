#include <iostream>
using namespace::std;

int validation(int);
int nEmployees();
int daysAbsent(int);
double average(int, int);

int main()
{
    int numEmployees, days;

    double averageDays;

    numEmployees = nEmployees();
    cout << endl;
    days = daysAbsent(numEmployees);
    cout << endl;
    averageDays = average(numEmployees, days);
    cout << endl;

    cout << "The number of employees is " << numEmployees << endl;
    cout << "The amount of days employees were absent is  " << days << endl;
    cout << "The average number of days absent is " << averageDays << endl;

    return 0;
} 

int validation(int num1, int num2)
{
    cin >> num1;
    while (num1 < num2) {
        cout << "Error, Integer must not be "
            << " less than " << num2 << ": ";
        cin >> num1;
    }
    return num1;
}


int nEmployees()
{
    int n = 0;

    cout << "Enter the number of employees in the company: ";
    return validation(n, 1);
    /* cout << "Enter the number of employees in the company: ";
    int result = validation(n, 1);
    cout << "The number of employees is " << result << endl;*/
}

int daysAbsent(int numEmployees)
{
    int sumDayAbsent = 0;

    cout << "Enter number of days each employee missed during the past year: " << endl;

    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Employee #" << (i + 1) << ": ";
        sumDayAbsent += validation(sumDayAbsent, 0);
    }

    return sumDayAbsent;
}


double average(int numEmployees, int days_absent)
{
    return days_absent / static_cast<double>(numEmployees);
}