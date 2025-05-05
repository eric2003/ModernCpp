#include <string>

struct S
{  
private:
    std::string value;
public:
    std::string & get_value() &
    {
        std::puts( "get_value() &" );
        return value;
    }
    std::string get_value() &&
    {
        std::puts( "get_value() &&" );
        return std::move( value );
    }
    const std::string & get_value() const &&
    {
        std::puts( "get_value() const &&" );
        return value;
    }

    const std::string & get_value() const &
    {
        std::puts( "get_value() const &" );
        return value;
    }
};  

void call( const S & obj ) {
    obj.get_value();
}

S get_obj() { return {}; }

int main()
{
    const S obj;
    std::move( obj ).get_value();
    return 0;  
}