// C++ program to demonstrate the
// problem occurred in string
#include <iostream>
#include <string_view>
using namespace std;
 
// Driver Code
int main(int argc, char* argv[])
{
    std::string_view str_1{ "Hello !!, GeeksforGeeks" };
 
    // View of the same "hello"
    std::string_view str_2{ str_1 };
 
    // View of the same "hello"
    std::string_view str_3{ str_2 };
 
    // Print the string
    std::cout << str_1 << '\n'
              << str_2 << '\n'
              << str_3 << '\n';
 
    return 0;
}
