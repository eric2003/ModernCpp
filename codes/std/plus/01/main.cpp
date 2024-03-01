// plus example
#include <iostream>     // std::cout
#include <functional>   // std::plus
#include <algorithm>    // std::transform

int main(int argc, char* argv[])
{
	int first[]={1,2,3,4,5};
	int second[]={10,20,30,40,50};
	int results[5];
	std::transform (first, first+5, second, results, std::plus<int>());
	for (int i=0; i<5; i++)
		std::cout << results[i] << ' ';
	std::cout << '\n';
	return 0;
}
