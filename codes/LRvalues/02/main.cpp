#include <iostream>  

struct X {  
    // ��ͨ�� lvalue �汾  
    void f() & {  
        std::cout << "Called f() on an lvalue." << std::endl;  
    }  

    // ��ͨ�� rvalue �汾  
    void f() && {  
        std::cout << "Called f() on an rvalue." << std::endl;  
    }  

    // const lvalue �汾  
    void f() const& {  
        std::cout << "Called f() on a const lvalue." << std::endl;  
    }  

    // const rvalue �汾  
    void f() const&& {  
        std::cout << "Called f() on a const rvalue." << std::endl;  
    }  
};  

int main() {  
    X x;                // x ��һ�� lvalue  
    const X cx;       // cx ��һ�� const lvalue  

    // ���� lvalue �� const lvalue �汾  
    x.f();            // ���: Called f() on an lvalue.  
    cx.f();          // ���: Called f() on a const lvalue.  

    // ���� rvalue �� const rvalue �汾  
    X().f();          // ���: Called f() on an rvalue.  
    const X().f();    // ���: Called f() on a const rvalue.  

    return 0;  
}  