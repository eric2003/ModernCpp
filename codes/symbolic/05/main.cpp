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
    constexpr formula ( Expression expr ) noexcept {};
    // Call operator where substitution happens
    //template <class ... Args >
    //constexpr auto operator ()( Args ... args ) const noexcept {
    //    return expression {}( substitution ( args ...));
    //}
};

template <typename Operator, typename ... Terms>
struct symbolic_expression {
};

template < typename Lhs, typename Rhs >
constexpr symbolic_expression < std::plus<void>, Lhs, Rhs > operator + ( Lhs, Rhs ) noexcept { return {};}

int main(int argc, char* argv[])
{
	// Defining mathematical symbols
	symbol a;
	symbol b;
	
	formula f = a + b;
	
	return 0;
}
