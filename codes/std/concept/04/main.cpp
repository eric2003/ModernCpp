#include <concepts>

auto Average(auto x, auto y) {
  return (x + y) / 2;
}

int main(int argc, char* argv[])
{
	Average(1, 2);
	Average(1.5, 2.2); 
	return 0;
}
