#include <type_traits>
#include <iostream>
#include <memory>
#include <functional>

template < typename Operator, typename ... Terms >
struct symbolic_expression {};

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::plus<void>, Lhs, Rhs > operator + ( Lhs , Rhs ) noexcept { return {}; }

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::minus<void>, Lhs, Rhs > operator - ( Lhs, Rhs ) noexcept { return {}; }

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::multiplies<void >, Lhs, Rhs > operator * ( Lhs, Rhs ) noexcept { return {}; }

template < typename Lhs, typename Rhs >
constexpr symbolic_expression< std::divides<void>, Lhs, Rhs > operator / ( Lhs , Rhs ) noexcept { return {}; }


int main( int argc, char* argv[] )
{
	return 0;
}
