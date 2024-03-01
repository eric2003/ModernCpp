#include <type_traits>
#include <iostream>

template <auto Value >
struct constant_symbol {
	using type = decltype ( Value );
	static constexpr type value = Value ;
};

// Type trait
template <class >
struct is_symbolic : std :: false_type {};

// Making it symbolic
template <auto Value >
struct is_symbolic < constant_symbol < Value > >: std::true_type {};

int main(int argc, char* argv[])
{
	return 0;
}
