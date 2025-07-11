#include <type_traits>
#include <iostream>
#include <memory>

template < typename >
struct symbol_id {
	static constexpr auto singleton = []{};
	static constexpr const void * address = std::addressof( singleton );
};

template < auto Id = symbol_id< decltype([]{})>{} >
struct symbol {
	static constexpr auto id = Id;
};

//template < typename Lhs, typename Rhs >
//constexpr bool opreator< ( symbol_id<Lhs>, symbol_id<Rhs> ) {
//	return symbol_id<Lhs>::address < symbol_id<Rhs>::address;
//}


template <class>
struct test_id {
};

template <class Lhs, class Rhs>
constexpr bool opreator<(test_id<Lhs>, test_id<Rhs>) {
	return true;
}

template <class>
struct my_id {
};

template <class Lhs, class Rhs>
constexpr bool operator<(my_id<Lhs>, my_id<Rhs>) {
    return true;
}
 
int main(int argc, char* argv[])
{
	symbol x;
	symbol y;
	
	//bool flag x < x;
	//std::cout << "x.id < x.id := " << ( x.id < x.id ) << std::endl; 
	//std:cout << "x.id < y.id := " << ( x.id < y.id ) << std::endl; 
	
	//std::cout << std::is_same_v< decltype(x), decltype(x) > << std::endl; 
	//std::cout << std::is_same_v< decltype(x), decltype(y) > << std::endl; 
	
	return 0;
}
