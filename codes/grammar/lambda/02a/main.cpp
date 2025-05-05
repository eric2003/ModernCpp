#include <iostream>
#include <functional>

int main() {  
    std::function<int(int)> f = [&](int i) {
        if ( i == 0 )
            return 1;
        return i * f( i - 1 );
    };

    std::cout << f( 5 ); //prints 120
    return 0;  
}