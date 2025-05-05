#include <iostream>
#include <array>

int main() {  
    const int count = 3;
    std::array<double, count> doubles {1.1, 2.2, 3.3};

    // but not double:
    const double dCount = 3.3;
    std::array<double, static_cast<int>(dCount)> moreDoubles {1.1, 2.2, 3.3};
    return 0;  
}