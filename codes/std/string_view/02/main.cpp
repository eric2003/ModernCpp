#include <print>
#include <string_view>

std::string Name() {
	return std::string("some long runtime value string");
}
 
// Driver Code
int main(int argc, char* argv[])
{
    const std::string & str = Name();
	std::print("{}\n", str);
	
    std::string_view sv = Name();
	std::print("{}\n", sv);
 
    return 0;
}
