#include <iostream>  

void legacy_call( int( *f )( int ) ) {
    std::cout << f( 7 ) << "\n";
}

int main() {  
    legacy_call( []( int i ) {
        return i * i;
        } );
    return 0;  
}