#include <iostream>
 
int main(int argc, char* argv[])
{
	//auto a = []{};

    auto lambda = []() { return 42; };
    std::cout << "Type of lambda: " << typeid(decltype(lambda)).name() << std::endl;

	return 0;
}
