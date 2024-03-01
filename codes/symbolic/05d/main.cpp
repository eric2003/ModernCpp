#include <type_traits>
#include <iostream>
#include <memory>
#include <functional>

struct symbol {
};

template < typename Expression >
struct formula {
    // Types and constants
    using expression = Expression;
    // Constructor
    constexpr formula ( Expression expr ) noexcept
	{
		std::cout << "constexpr formula" << std::endl;
		std::cout << "typeid( decltype(expr) ).name() = " << typeid( decltype(expr) ).name() << std::endl;
	};
    // Call operator where substitution happens
    //template <class ... Args >
    //constexpr auto operator ()( Args ... args ) const noexcept {
    //    return expression {}( substitution ( args ...));
    //}
};

struct sin_symbol {
	template < typename Arg >
	constexpr auto operator ()( Arg && arg ) {
		return std::sin( std::forward< Arg >( arg ) );
	}
};

template <typename Operator, typename ... Terms>
struct symbolic_expression {
};

template <typename Arg>
constexpr symbolic_expression < sin_symbol, Arg > mysin( Arg ) noexcept 
{ 
	std::cout << "symbolic_expression < sin_symbol, Arg >" << std::endl;
	return {};
}

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::plus<void>, Lhs, Rhs > operator + ( Lhs, Rhs ) noexcept { return {};}

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::minus<void>, Lhs, Rhs > operator - ( Lhs, Rhs ) noexcept { return {};}

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::multiplies<void>, Lhs, Rhs > operator * ( Lhs, Rhs ) noexcept { return {};}

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::divides<void>, Lhs, Rhs > operator / ( Lhs, Rhs ) noexcept { return {};}

int main(int argc, char* argv[])
{
	// Defining mathematical symbols
	symbol a;
	symbol b;
	symbol c;
	
	formula f = a + b - c;
	formula g = a * b;
	formula h = a / b;
	formula i = a / b - c;
	formula j = mysin( a );
	
	
	return 0;
}
