#include <type_traits>
#include <iostream>

struct is_symbolic : std::true_type {};

int main(int argc, char* argv[])
{
    std::cout << "true_type == " << std::boolalpha
        << is_symbolic::value << std::endl;	
	return 0;
}
