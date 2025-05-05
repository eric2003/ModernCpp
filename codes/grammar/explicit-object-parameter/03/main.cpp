#include <iostream>  

struct Base {  
    template<typename Self>  
    void f(this Self&& self) {  
        std::cout << "f(this Self&& self)." << std::endl;  
    }  
};  

struct Derived : Base {};

int main() {  
    Base b;
    b.f();               // Self = Base&
    std::move( b ).f();  // Self = Base
    Derived d;           // Self = Derived&
    d.f();
    return 0;  
}