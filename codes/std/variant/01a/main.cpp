#include <variant>
#include <string>
#include <print>

std::variant<int, double, std::string> get_value()
{
    return 42;
}

int main(int argc, char* argv[])
{
    std::visit( []( const auto & ) {}, get_value() );
    return 0;
}