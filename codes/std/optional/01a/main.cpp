#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b)  
{  
    if (b == 0)  
    {  
        return std::nullopt; // Indicates that the division is not possible  
    }  
    return a / b;  
}  

int main() {
    int a = 10;  
    int b = 0;  
    auto result = divide(a, b);  
    if (result.has_value())   
    {  
        std::cout << "Result of division: " << result.value() << std::endl;  
    }  
    else  
    {  
        std::cout << "Division by zero is not possible." << std::endl;  
    }

    return 0;
}