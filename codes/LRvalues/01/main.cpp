#include <iostream>  

struct X {  
    void f() & { // ֻ���� lvalue �ϵ���  
        std::cout << "Called f() on an lvalue." << std::endl;  
    }  

    void f() && { // ֻ���� rvalue �ϵ���  
        std::cout << "Called f() on an rvalue." << std::endl;  
    }  
};  

int main() {  
    X x;          // x ��һ�� lvalue  
    x.f();       // ���� lvalue �޶����汾  

    X().f();     // ���� rvalue �޶����汾��X() ��һ�� rvalue  

    return 0;  
}  
