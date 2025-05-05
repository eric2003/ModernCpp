#include <iostream>
#include <map>
// might be optimized to compile-time if compiled decides...
const int importantNum = 42;

// will be inited at runtime
std::map<std::string, double> buildMap()
{
    return std::map<std::string, double>();
}

int main() {  
    const std::map<std::string, double> countryToPopulation = buildMap();
    return 0;  
}