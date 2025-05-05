#include <iostream>

int main() {  
    auto fibonacci = []( this auto&& self, int n ) {
        if ( n < 2 )
            return n;
        return self( n - 1 ) + self( n - 2 ); 
    };

    std::cout << fibonacci( 5 ) << "\n";
    return 0;  
}