#include <iostream>
int multiply(int, int);

using namespace std;

int main()
{
    int a = 5;
    int b = 3;
    int c;
    c = multiply(a, b);
    cout << c;
    return 0;
}

int multiply(int a, int b)
{
    int c = a*b;
    return c;
}
