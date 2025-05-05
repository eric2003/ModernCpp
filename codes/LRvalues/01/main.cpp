#include <iostream>  

struct X {  
    void f() & { // 只能在 lvalue 上调用  
        std::cout << "Called f() on an lvalue." << std::endl;  
    }  

    void f() && { // 只能在 rvalue 上调用  
        std::cout << "Called f() on an rvalue." << std::endl;  
    }  
};  

int main() {  
    X x;          // x 是一个 lvalue  
    x.f();       // 调用 lvalue 限定符版本  

    X().f();     // 调用 rvalue 限定符版本，X() 是一个 rvalue  

    return 0;  
}  
