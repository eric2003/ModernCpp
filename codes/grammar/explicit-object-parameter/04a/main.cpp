#include <string>
#include <type_traits>
#include <iostream>

struct S
{  
private:
    std::string value;
public:
    auto get_value( this auto && self ) -> decltype(auto) {
        return std::forward_like<decltype( self )>( self.value );
    }
};  

void call( const S & obj ) {
    obj.get_value();
}

S get_obj() { return {}; }

int main()
{
    const S obj;
    std::cout << std::is_rvalue_reference_v<decltype( obj.get_value() )>;
    return 0;  
}