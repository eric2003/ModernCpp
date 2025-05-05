#include <iostream>
#include <vector>

int main(int, const char* argv[])
{
    std::vector data{ 11,22,33 };

    for ( auto i = 0; i < data.size(); ++ i )
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}