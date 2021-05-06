#include <iostream>
#include <memory>
using namespace std;

class Obj
{
	public:
		Obj() { cout << "Constructed!" << endl; }
		~Obj() { cout << "Desrtrucetd!" << endl; }
};

int main()
{

	{
		unique_ptr<Obj> ob(new Obj);
	}

	return 0;
}