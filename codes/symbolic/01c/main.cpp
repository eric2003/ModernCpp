#include <type_traits>
#include <iostream>

template < auto = []{} >
struct symbol {};
 
int main(int argc, char* argv[])
{
	symbol a;
	symbol w;
	symbol t;
	symbol phi;
	
	std::cout << std::is_same_v< decltype(a), decltype(w) > << std::endl; 

	return 0;
}
