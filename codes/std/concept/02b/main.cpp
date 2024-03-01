#include <iostream>
#include <concepts>

template <typename T>
  requires std::integral<T>
T Average(T x, T y) {
  std::cout << "Using integral function\n";
  return (x + y) / 2;
}

template <typename T>
  requires std::floating_point<T>
T Average(T x, T y) {
  std::cout << "Using floating point function";
  return (x + y) / 2;
}

int main(int argc, char* argv[])
{
    Average(1, 2);
    Average(1.5, 2.2); 
	return 0;
}
