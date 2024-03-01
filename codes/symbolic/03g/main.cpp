#include <type_traits>
#include <iostream>
#include <memory>
#include <functional>

// Type trait
template <typename >
struct is_symbolic : std::false_type {};

// Variable template
template <typename T >
inline constexpr bool is_symbolic_v = is_symbolic<T>::value;

// Concept
template <class T >
concept symbolic = is_symbolic_v<T>;

template < typename Operator, symbolic ... Terms >
struct symbolic_expression {};

template < symbolic Lhs, symbolic Rhs >
constexpr symbolic_expression< std::plus<void>, Lhs, Rhs > operator + ( Lhs , Rhs ) noexcept { return {}; }

template < symbolic Lhs, symbolic Rhs >
constexpr symbolic_expression< std::minus<void>, Lhs, Rhs > operator - ( Lhs, Rhs ) noexcept { return {}; }

template < symbolic Lhs, symbolic Rhs >
constexpr symbolic_expression< std::multiplies<void >, Lhs, Rhs > operator * ( Lhs, Rhs ) noexcept { return {}; }

template < symbolic Lhs, symbolic Rhs >
constexpr symbolic_expression< std::divides<void>, Lhs, Rhs > operator / ( Lhs , Rhs ) noexcept { return {}; }


int main( int argc, char* argv[] )
{
	return 0;
}
