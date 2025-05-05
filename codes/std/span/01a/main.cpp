#include <span> 

void use_data( std::span<const int> data );

int main(int argc, char* argv[])
{ 
    use_data( { 1,2,3,4 } );
    return 0; 
}

