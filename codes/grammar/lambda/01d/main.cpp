#include <iostream>  
#include <variant>

template <typename... Ts>
struct overload : Ts... {
    using Ts::operator()...;
};

int main() {  
    overload f = {
        []( int i ) { std::cout << "int thingy\n"; },
        []( float f ) { std::cout << "float thingy\n"; }
    };

    std::variant<int, float> v = 2.0f;
    std::variant<int, float> w = 2;
    std::visit( f, v ); //prints float thingy
    std::visit( f, w ); //prints int thingy
    return 0;  
}