// plus example
#include <iostream>     // std::cout
#include <functional>   // std::plus
#include <algorithm>    // std::transform

int main(int argc, char* argv[])
{
	auto int_plus = std::plus<int>{};
	auto v = int_plus(4.2, 3.9);
	// decltype(v) == int, v == 7 (4+3)
	std::cout << "typeid( decltype(v) ).name() = " << typeid( decltype(v) ).name() << std::endl;
	std::cout << "v = " << v << std::endl;
	return 0;
}
