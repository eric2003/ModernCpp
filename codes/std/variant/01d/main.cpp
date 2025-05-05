#include <variant>
#include <string>
#include <print>

struct Lambda {
    auto operator()( const auto & param ) {
        std::print( "{}", param );
    }
};

std::variant<int, double, std::string> get_value()
{
    return 42;
}

int main(int argc, char* argv[])
{
    const auto & value = get_value();
    Lambda l;
    if ( std::holds_alternative<int>( value ) ) {
        l( std::get<int>( value ) );
    }
    else if ( std::holds_alternative<double>( value ) ) {
        l( std::get<double>( value ) );
    }
    else if ( std::holds_alternative<std::string>( value ) ) {
        l( std::get<std::string>( value ) );
    }
    return 0;
}