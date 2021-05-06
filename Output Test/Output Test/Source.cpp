#include <iostream>
using namespace std;

template<class T>
T Total(T a)
{
    T number;
    static T sumTotal = 0;
    if (a > 0)
    {

        cout << "Ingrese el número: " << endl;
        cin >> number;
        sumTotal += number;
        Total(a - 1);

    }

    return sumTotal;

}
int main()
{

    int size;



    cout << "Entre la cantidad valores  \n";
    cin >> size;

    cout << "Total: " << Total(size) << endl;


    return 0;
}

/*Entre la cantidad valores
3
Ingrese el número:
1
Ingrese el número:
2
Ingrese el número:
3
6*/