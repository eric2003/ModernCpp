#include <iostream>
#include <type_traits>

struct A {
    int foo() { return 10; }
};

int main(int argc, char* argv[])
{
    using ReturnType = decltype(std::declval<A>().foo());
    std::cout << "Return type of A::foo(): " << typeid(ReturnType).name() << std::endl;
 
    return 0;
}
