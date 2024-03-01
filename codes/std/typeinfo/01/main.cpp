#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>
 
struct Base { virtual ~Base() = default; };
struct Derived : Base {};
 
int main(int argc, char* argv[])
{
    Base b1;
    Derived d1;
 
    const Base* pb = &b1;
    std::cout << typeid(*pb).name() << '\n';
    pb = &d1;
    std::cout << typeid(*pb).name() << '\n';
 
    std::string s = typeid(pb).name();
	
	std::cout << "s = " << s << '\n';

	return 0;
}
