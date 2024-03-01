//#include <type_traits>
#include <iostream>
#include <typeinfo>

template < auto = []{} >
struct symbol {};
 
int main(int argc, char* argv[])
{
	symbol a;
	symbol phi;
	//std::type_info::hash_code;
	std::cout << "std::type_info(a).hash_code() = " << std::type_info(a).hash_code() << << std::endl; 
	
	return 0;
}
