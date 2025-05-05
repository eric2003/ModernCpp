#include <iostream>  

template <typename T>
constexpr auto c_cast = []( auto x ) {
    return (T)x;
};

int main() {  
    std::cout << " c_cast<int>( 3.14159 ) = " << c_cast<int>( 3.14159 ) << "\n";
    return 0;  
}