#include <type_traits>
#include <iostream>

template < auto = []{} >
struct symbol {};
 
int main(int argc, char* argv[])
{
	symbol x;
	symbol y;
	
	std::cout << std::is_same_v< decltype(x), decltype(x) > << std::endl; 
	std::cout << std::is_same_v< decltype(x), decltype(y) > << std::endl; 

	return 0;
}
