#include <iostream>  
#include <format>

int main(int argc, char* argv[])
{
    float number = 4.3100f;
    std::cout << std::format("Hello {}!\n", "world");
    std::cout << std::format("f= {:f}\n", number);
    std::cout << std::format("f= {:g}\n", number);
    std::cout << std::format("f= {:.1g}\n", number);
    std::cout << std::format("f= {:.2g}\n", number);
    std::cout << std::format("f= {:.3g}\n", number);
    std::cout << std::format("f= {:.4g}\n", number);

    return 0;  
}  
