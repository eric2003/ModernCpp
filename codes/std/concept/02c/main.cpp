#include <concepts>

template <typename T>
  requires std::integral<T> ||
           std::floating_point<T>
T Average(T x, T y) {
  return (x + y) / 2;
}

int main(int argc, char* argv[])
{
    Average(1, 2);
    Average(1.5, 2.2); 
	return 0;
}
