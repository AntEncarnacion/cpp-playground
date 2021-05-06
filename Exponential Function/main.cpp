#include <iostream>

using namespace std;

int pow(int baseNum, int powNum){
    int result = 1;
    for(int i = 0; i < powNum; i ++){
        result = result * baseNum;
    }
    return result;
}

int main()
{
    int baseNum, powNum;
    cout << pow(4, 2);
    return 0;
}
