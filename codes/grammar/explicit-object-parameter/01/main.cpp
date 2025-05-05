#include <iostream>

struct X
{
	void f()
	{
		std::cout << "X:f()\n";
	}
};

struct Y
{
	void g( this Y& self )
	{
		std::cout << "Y:g( this Y& self)\n";
	}
};

int main(int argc, char* argv[])
{
	X x;
	x.f();
	Y y;
	y.g();
	return 0;
}
