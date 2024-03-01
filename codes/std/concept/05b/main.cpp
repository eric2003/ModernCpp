#include <string>

template <typename T>
concept Averagable =
requires(T x, T y){
  (x + y) / 2;
};

template <Averagable T>
T Average(T x, T y){ return (x + y) / 2; }

int main(int argc, char* argv[])
{
	Average(3, 5);
	
	std::string A{"Hello"};
	std::string B{"World"};
	Average(A, B);
	return 0;
}
