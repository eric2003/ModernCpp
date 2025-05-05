#include <iostream>  

template <typename T>  
class Example {  
public:  
    template <typename U>  
    U get() { return U(); }  
};  


int main() {  
    Example<int> value;  
    auto result = value.template get<std::string>();  // 需要使用 template  
    std::string a = value.get<std::string>();
    int b = value.get<int>();
    int kkk = 1;
    return 0;  
}