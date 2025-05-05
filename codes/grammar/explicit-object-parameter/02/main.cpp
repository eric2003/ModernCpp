#include <iostream>  

struct X {  
    // lvalue �汾  
    void f(this X&) {  
        std::cout << "Called f() on an lvalue (explicit). " << std::endl;  
    }  

    // rvalue �汾  
    void f(this X&&) {  
        std::cout << "Called f() on an rvalue (explicit). " << std::endl;  
    }  

    // const lvalue �汾  
    void f(this const X&) {  
        std::cout << "Called f() on a const lvalue (explicit). " << std::endl;  
    }  

    // const rvalue �汾  
    void f(this const X&&) {  
        std::cout << "Called f() on a const rvalue (explicit). " << std::endl;  
    }  
};  

int main() {  
    X x;                  // x ��һ�� lvalue  
    const X cx;          // cx ��һ�� const lvalue  

    // ���� lvalue �� const lvalue �汾  
    x.f();               // ���: Called f() on an lvalue (explicit).  
    cx.f();             // ���: Called f() on a const lvalue (explicit).  

    // ���� rvalue �� const rvalue �汾  
    X().f();             // ���: Called f() on an rvalue (explicit).  
    const X().f();       // ���: Called f() on a const rvalue (explicit).  

    return 0;  
}