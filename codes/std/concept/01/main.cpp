#include <iostream>
#include <concepts>

int main(int argc, char* argv[])
{
    if constexpr (std::integral<int>) {
      std::cout << "int is an integral";
    }
    
    if constexpr (!std::integral<float>) {
      std::cout << "\nfloat isn't an integral";
    }
	return 0;
}
