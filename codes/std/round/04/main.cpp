#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    double result;

    int num = 15;
    result = std::round(num);

    std::cout << "round(" << num << ") = " << result << std::endl;

    return 0;
}

