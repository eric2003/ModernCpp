import std;

struct Base{
    template<typename Self>
    void work(this Self&& self) {
        self.do_work();
    }
    void do_work() {
        std::cout << "Base do_work\n";
    }
};

struct A : Base {
    void do_work() {
        std::cout << "A do_work\n";
    }
};

struct B : Base {
    void do_work() {
        std::cout << "B do_work\n";
    }
};


int main() {  
    std::vector<Base * > bases;
    bases.push_back( new Base() );
    bases.push_back( new A() );
    bases.push_back( new B() );
    for ( Base * b : bases )
    {
        b->work();
    }
    for ( Base * b : bases )
    {
        delete b;
    }

    return 0;  
}