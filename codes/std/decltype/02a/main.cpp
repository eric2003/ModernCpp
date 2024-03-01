#include <iostream>
#include <utility>

//C++11
template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype (std::forward<T>(t) + std::forward<U>(u))
        { return std::forward<T>(t) + std::forward<U>(u); };
		
//C++14
template<typename T, typename U>
decltype(auto) myFunc2(T&& t, U&& u)
        { return std::forward<T>(t) + std::forward<U>(u); };
 
int main(int argc, char* argv[])
{
    std::cout << "myFunc(1,2.7) = " << myFunc(1,2.7) << "\n";
	std::cout << "myFunc2(1,2.7) = " << myFunc2(1,2.7) << "\n";
	std::cout << "int is: " << typeid(int).name() << '\n';
	std::cout << "typeid(myFunc2(1,2.7)).name() = " << typeid(myFunc2(1,2.7)).name() << "\n";
	
	return 0;
}
