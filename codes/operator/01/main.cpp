#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    void display() {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex sum = c1 + c2;
    sum.display();	
	return 0;
}
