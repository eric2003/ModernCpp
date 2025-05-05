#include <iostream>

int main() {  
    auto f = []( auto&& self, int i ) {
        if ( i == 0 )
            return 1;
        return i * self( self, i - 1 ); 
    };

    std::cout << f( f, 5 ); //prints 120
    return 0;  
}