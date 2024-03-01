#include <type_traits>
#include <iostream>
#include <memory>

//Remove lvalue references
template <class T >
struct remove_lvalue_reference : std::type_identity <T> {};

template <class T >
requires std :: is_lvalue_reference_v<T>
struct remove_lvalue_reference <T>: std::type_identity < std::remove_reference_t<T> > {};

template <class T >
using remove_lvalue_reference_t = remove_lvalue_reference<T>::type;

//Remove rvalue references
template <class T >
struct remove_rvalue_reference : std::type_identity <T>{};

template <class T >
requires std::is_rvalue_reference_v<T>
struct remove_rvalue_reference <T>: std::type_identity < std::remove_reference_t<T> >{};

template <class T >
using remove_rvalue_reference_t = remove_rvalue_reference <T>::type;

template < typename >
struct symbol_id {
	static constexpr auto singleton = []{};
	static constexpr const void * address = std::addressof( singleton );
};

template < typename Symbol, typename T >
struct symbol_binder {
	typedef T value_type;
	constexpr symbol_binder( Symbol, value_type x):value(x){}
	static constexpr Symbol symbol = {};
	T value;
};

template < auto Id = symbol_id< decltype([]{})>{} >
struct symbol {
	static constexpr auto id = Id;
	template < typename T >
	constexpr symbol_binder<symbol,T> operator=( T value){
		return symbol_binder(*this, value);
	}	
};

template <class Lhs , class Rhs >
constexpr std::strong_ordering operator <=>(
    symbol_id< Lhs >,
    symbol_id< Rhs >
) {
      return std::compare_three_way {} (
           symbol_id< Lhs >::address,
           symbol_id< Rhs >::address
      );
}

int main(int argc, char* argv[])
{
	symbol x;
	symbol y;
	symbol z;
	
	std::cout << "x.id < x.id := " << ( x.id < x.id ) << std::endl; 
	std::cout << "x.id < y.id := " << ( x.id < y.id ) << std::endl; 
	std::cout << "y.id < x.id := " << ( y.id < x.id ) << std::endl; 
	std::cout << "x.id < z.id := " << ( x.id < z.id ) << std::endl; 
	std::cout << "z.id < x.id := " << ( z.id < x.id ) << std::endl; 
	std::cout << "y.id < z.id := " << ( y.id < z.id ) << std::endl; 
	std::cout << "z.id < y.id := " << ( z.id < y.id ) << std::endl; 
	
	//std::cout << std::is_same_v< decltype(x), decltype(x) > << std::endl; 
	//std::cout << std::is_same_v< decltype(x), decltype(y) > << std::endl; 
	
	return 0;
}
