#include <type_traits>
#include <iostream>
 
int main(int argc, char* argv[])
{
	auto a = []{};
	auto b = []{};
	auto c = []{};
	auto d = []{};
	
	std::cout << std::is_same_v< decltype(a), decltype(a) > << std::endl; 
	std::cout << std::is_same_v< decltype(a), decltype(b) > << std::endl; 

	return 0;
}
