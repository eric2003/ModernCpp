//#include <concepts>

template <auto Value >
struct constant_symbol {
	using type = decltype ( Value );
	static constexpr type value = Value ;
}

// Making it symbolic
template <auto Value >
struct is_symbolic < constant_symbol < Value > >: std::true_type {};

int main(int argc, char* argv[])
{
	return 0;
}
