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
    //std::visit( []( const auto & value ) {
    //    std::print( "{}", value );
    //    }, get_value() );
    std::visit( Lambda(), get_value() );
    return 0;
}