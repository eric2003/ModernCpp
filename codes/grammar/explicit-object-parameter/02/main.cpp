#include <iostream>  

struct X {  
    // lvalue 版本  
    void f(this X&) {  
        std::cout << "Called f() on an lvalue (explicit). " << std::endl;  
    }  

    // rvalue 版本  
    void f(this X&&) {  
        std::cout << "Called f() on an rvalue (explicit). " << std::endl;  
    }  

    // const lvalue 版本  
    void f(this const X&) {  
        std::cout << "Called f() on a const lvalue (explicit). " << std::endl;  
    }  

    // const rvalue 版本  
    void f(this const X&&) {  
        std::cout << "Called f() on a const rvalue (explicit). " << std::endl;  
    }  
};  

int main() {  
    X x;                  // x 是一个 lvalue  
    const X cx;          // cx 是一个 const lvalue  

    // 调用 lvalue 和 const lvalue 版本  
    x.f();               // 输出: Called f() on an lvalue (explicit).  
    cx.f();             // 输出: Called f() on a const lvalue (explicit).  

    // 调用 rvalue 和 const rvalue 版本  
    X().f();             // 输出: Called f() on an rvalue (explicit).  
    const X().f();       // 输出: Called f() on a const rvalue (explicit).  

    return 0;  
}