#include <iostream>
#include <type_traits>
 
class A {};
class B : A {};
class C : B {};
class D {};
union E {};
using I = int;
 
int main(int argc, char* argv[])
{
	std::is_base_of_v<A, A> == true &&
	std::cout << "std::is_base_of_v<A, A>="<< std::is_base_of_v<A, A> << std::endl;
	std::cout << "std::is_base_of_v<A, B>="<< std::is_base_of_v<A, B> << std::endl;
	std::cout << "std::is_base_of_v<A, C>="<< std::is_base_of_v<A, C> << std::endl;
	std::cout << "std::is_base_of_v<A, D>="<< std::is_base_of_v<A, D> << std::endl;
	std::cout << "std::is_base_of_v<B, A>="<< std::is_base_of_v<B, A> << std::endl;
	std::cout << "std::is_base_of_v<E, E>="<< std::is_base_of_v<E, E> << std::endl;
	std::cout << "std::is_base_of_v<I, I>="<< std::is_base_of_v<I, I> << std::endl;
	return 0;
}
