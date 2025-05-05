import std;

void PrintVector( std::vector<std::string > & v )
{
    for ( int i = 0; i < v.size(); ++ i )
    {
        std::print( "{} ", v[ i ] );
    }
    std::print( "\n" );
}

int main() {  
    std::vector<std::string > v{ "a", "b", "c", "d", "e" };
    PrintVector( v );
    std::ranges::shift_left( v, 2 );
    PrintVector( v );
    std::ranges::shift_right( v, 1 );
    PrintVector( v );
    return 0;  
}  

