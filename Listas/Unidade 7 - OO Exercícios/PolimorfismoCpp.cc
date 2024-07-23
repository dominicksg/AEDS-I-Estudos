#include <iostream>

using namespace std;

// clear && g++ IntroCpp.cc && ./a.out

// Polimorfismo = Overload = Sobrecarga

void fn()
{
	cout << "OI" << endl;
}

void fn(int n)
{
	cout << "TCHAU" << endl;
}

int main()
{
	int eae;
	fn();
	fn(eae);

	return 0;
}