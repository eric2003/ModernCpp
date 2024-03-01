#include <iostream>
 
 
int main(int argc, char* argv[])
{
    std::cout << "typeid(int).name() = " << typeid(int).name() << "\n";
	std::cout << "typeid(double).name() = " << typeid(double).name() << "\n";
	std::cout << "typeid(long double).name() = " << typeid(long double).name() << "\n";
	
	return 0;
}
