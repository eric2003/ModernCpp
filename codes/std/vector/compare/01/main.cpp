#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    {
        std::vector<int> a;
        std::vector<int> b;
        a.push_back( 1 );
        b.push_back( 2 );

        bool flag = a < b;

        std::cout << "flag1 = " << flag << "\n";
    }

    {
        std::vector<int> a;
        std::vector<int> b;
        a.push_back( 1 );
        a.push_back( 2 );
        b.push_back( 2 );

        bool flag = a < b;

        std::cout << "flag2 = " << flag << "\n";
    }

    {
        std::vector<int> a;
        std::vector<int> b;
        a.push_back( 1 );
        a.push_back( 2 );
        b.push_back( 1 );

        bool flag = a < b;

        std::cout << "flag3 = " << flag << "\n";
    }

    return 0;
}

