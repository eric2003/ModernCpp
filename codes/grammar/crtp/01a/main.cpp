#include <iostream>  

struct Base{
    template<typename Self>
    void work(this Self&& self) {
        self.do_work();
    }
    void do_work() {
        std::cout << "Base do_work\n";
    }
};

struct Derived : Base {
    void do_work() {
        std::cout << "Derived do_work\n";
    }
};

int main() {  
    Base b;
    b.work();
    Derived d;
    d.work();
    return 0;  
}