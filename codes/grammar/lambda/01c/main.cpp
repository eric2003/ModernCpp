#include <iostream>  

template <typename... Ts>
struct overload : Ts... {
    using Ts::operator()...;
};

int main() {  
    overload f = {
        []( int i ) { std::cout << "int thingy\n"; },
        []( float f ) { std::cout << "float thingy\n"; }
    };
    f( 2 ); //prints int thingy
    f( 2.0f ); //prints float thingy
    return 0;  
}