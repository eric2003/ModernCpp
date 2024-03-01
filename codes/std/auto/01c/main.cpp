#include <type_traits>
#include <iostream>

// Making it symbolic
template <typename Value >
struct is_symbolic: std::true_type {};

int main(int argc, char* argv[])
{
    std::cout << "std::true_type == " << std::boolalpha << std::true_type::value << std::endl;
	std::cout << "is_symbolic<int>::value == " << std::boolalpha 
	<< is_symbolic<int>::value << std::endl;
	std::cout << "is_symbolic<float>::value == " << std::boolalpha 
	<< is_symbolic<float>::value << std::endl;
	std::cout << "is_symbolic<void>::value == " << std::boolalpha 
	<< is_symbolic<void>::value << std::endl;
		
	return 0;
}
