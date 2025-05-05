import std;

int main() {  
    for ( int i : std::views::iota( 1, 10 ) )
        std::print( "{} ", i );
    std::print( "\n" );
    return 0;  
}  

