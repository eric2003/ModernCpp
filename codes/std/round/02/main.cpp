#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    double num, result;

    num = -11.16;
    result = round(num);

    std::cout << "round(" << num << ") = " << result << std::endl;

    num = -13.87;
    result = round(num);

    std::cout << "round(" << num << ") = " << result << std::endl;

    num = -50.5;
    result = round(num);

    std::cout << "round(" << num << ") = " << result << std::endl;

    return 0;
}

