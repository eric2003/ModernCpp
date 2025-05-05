#include <iostream>  

int main() {  
    auto f = []( int i ) {
        if ( i == 0 )
            return 1;
        return i * f( i - 1 ); //error: 'f' declared with auto
                               // cannot appear in its own initialiser!
    };
    std::cout << f( 5 );
    return 0;  
}