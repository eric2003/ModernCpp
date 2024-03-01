#include <iostream>
 
int main(int argc, char* argv[])
{
    int i = 5; 
    float j = 1.0; 
    char c = 'a'; 
  
    // Print the types 
    std::cout << "typeid(i * j).name() = " << typeid(i * j).name()  << std::endl; 
 
    std::cout << "typeid(i * c).name() = " << typeid(i * c).name()  << std::endl; 
	
	std::cout << "typeid(c).name() = " << typeid(c).name() << std::endl; 
  
    return 0;
}
