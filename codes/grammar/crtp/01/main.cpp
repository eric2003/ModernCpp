#include <iostream>  

template<typename T>
struct Base{
    void work() {
        T & derived = static_cast<T&>(*this);
        derived.do_work();
    }
};

struct Derived : Base<Derived> {
    void do_work() {
        std::cout << "Derived do_work\n";
    }
};

int main() {  
    Derived d;
    d.work();
    return 0;  
}