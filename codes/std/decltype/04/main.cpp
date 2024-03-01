#include <cassert>
#include <iostream>
#include <type_traits>
 
struct A { double x; };
const A* a;
 

int main(int argc, char* argv[])
{
	decltype(a->x) y;       // type of y is double (declared type)
	decltype((a->x)) z = y; // type of z is const double& (lvalue expression)
	
	std::cout << "typeid(y).name() = " << typeid(y).name()  << std::endl; 
	std::cout << "typeid(z).name() = " << typeid(z).name()  << std::endl; 
	std::cout << "typeid(A).name() = " << typeid(A).name()  << std::endl; 
	std::cout << "typeid(a).name() = " << typeid(a).name()  << std::endl; 
	
	return 0;
}
