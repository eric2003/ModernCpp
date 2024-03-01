// C++ program to illustrate the
// lvalue and rvalue
#include <iostream>
 
int main(int argc, char* argv[])
{
    int a = 10;
 
    // Declaring lvalue reference
    // (i.e variable a)
    int& lref = a;
 
    // Declaring rvalue reference
    int&& rref = 20;
 
    // Print the values
    std::cout << "lref = " << lref << std::endl;
    std::cout << "rref = " << rref << std::endl;
 
    // Value of both a
    // and lref is changed
    lref = 30;
 
    // Value of rref is changed
    rref = 40;
    std::cout << "lref = " << lref << std::endl;
    std::cout << "rref = " << rref << std::endl;
 
    // This line will generate an error
    // as l-value cannot be assigned
    // to the r-value references
    // int &&ref = a;
    return 0;
}
