// C++ program to demonstrate the
// problem occurred in string
#include <iostream>
#include <string>
using namespace std;
 
// Driver Code
int main(int argc, char* argv[])
{
    char str_1[]{ "Hello !!, GeeksforGeeks" };
 
    std::string str_2{ str_1 };
    std::string str_3{ str_2 };
 
    // Print the string
    std::cout << str_1 << '\n'
              << str_2 << '\n'
              << str_3 << '\n';
 
    return 0;
}
