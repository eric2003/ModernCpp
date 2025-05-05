#include <string>
#include <iostream>
#include <sstream>      // std::istringstream

template < typename T >
inline T StringToDigit( const std::string & str )
{
    T value;
    std::istringstream stream( str );
    stream >> std::dec >> value;
    return value;
}

template <typename T>  
class Example {  
public:
    template <typename U>  
    U get()
    {
        U v = StringToDigit<U>( data );
        return v;
    }
public:
    std::string data;
};  


int main() {  
    Example<int> value;
    value.data = "1.234";
    int a = value.get<int>();
    float b = value.get<float>();
    double c = value.template get<double>();
    int kkk = 1;
    return 0;  
}