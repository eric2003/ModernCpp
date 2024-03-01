#include <string>
#include <concepts>

template<typename T>
concept has_string_data_member = requires(T v) { 
    { v.name_ } -> std::convertible_to<std::string>; 
};

struct Person {
    int age_ { 0 };
    std::string name_;
};

struct Box {
    double weight_ { 0.0 };
    double volume_ { 0.0 };
};

int main(int argc, char* argv[])
{
    static_assert(has_string_data_member<Person>);
    static_assert(!has_string_data_member<Box>);
	return 0;
}
