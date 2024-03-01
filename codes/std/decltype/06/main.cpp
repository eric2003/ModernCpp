// declval example
#include <utility>      // std::declval
#include <iostream>     // std::cout

struct A {              // abstract class
  virtual int value() = 0;
};

class B : public A {    // class with specific constructor
  int val_;
public:
  B(int i,int j):val_(i*j){}
  int value() {return val_;}
};

int main(int argc, char* argv[])
{
	decltype(std::declval<A>().value()) a;  // int a
	decltype(std::declval<B>().value()) b;  // int b
	decltype(B(0,0).value()) c;   // same as above (known constructor)
	a = b = B(10,2).value();
	std::cout << a << '\n';
	return 0;
}
