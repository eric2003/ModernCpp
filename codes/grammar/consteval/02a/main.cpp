#include <iostream>

consteval int f( int i ) { return i; }

constexpr int g( int i )
{
    if consteval {
        return f( i ) + 1; // imediate function context
    }
    else {
        return 42;
    }
}

int main(int, const char* argv[])
{
    return 0;
}