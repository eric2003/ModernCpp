#include <concepts>
#include <iostream>

template <typename T>
  requires std::integral<T> ||
           std::floating_point<T>
T Average(T x, T y) {
	if ( std::is_integral<T>::value )
	{
	  std::cout << "Using integral function\n";
    }
    else if ( std::is_floating_point<T>::value )
    {
		std::cout << "Using floating point function";
    }
    return (x + y) / 2;
}

int main(int argc, char* argv[])
{
    Average(1, 2);
    Average(1.5, 2.2); 
	return 0;
}
