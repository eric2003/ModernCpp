#include <iostream>  

struct X {  
    // 普通的 lvalue 版本  
    void f() & {  
        std::cout << "Called f() on an lvalue." << std::endl;  
    }  

    // 普通的 rvalue 版本  
    void f() && {  
        std::cout << "Called f() on an rvalue." << std::endl;  
    }  

    // const lvalue 版本  
    void f() const& {  
        std::cout << "Called f() on a const lvalue." << std::endl;  
    }  

    // const rvalue 版本  
    void f() const&& {  
        std::cout << "Called f() on a const rvalue." << std::endl;  
    }  
};  

int main() {  
    X x;                // x 是一个 lvalue  
    const X cx;       // cx 是一个 const lvalue  

    // 调用 lvalue 和 const lvalue 版本  
    x.f();            // 输出: Called f() on an lvalue.  
    cx.f();          // 输出: Called f() on a const lvalue.  

    // 调用 rvalue 和 const rvalue 版本  
    X().f();          // 输出: Called f() on an rvalue.  
    const X().f();    // 输出: Called f() on a const rvalue.  

    return 0;  
}  