#include <iostream>  
#include <format>

int main(int argc, char* argv[])
{
    double number = 1234.56789;  

    // ��ʽ��Ϊ�̶�С��λ��  
    std::string formatted_fixed = std::format("{:.2f}", number);  
    std::cout << "Fixed format: " << formatted_fixed << std::endl;  

    // ��ʽ��Ϊ��ѧ������  
    std::string formatted_scientific = std::format("{:.2e}", number);  
    std::cout << "Scientific format: " << formatted_scientific << std::endl;  

    // ��ʽ��Ϊͨ�ø�ʽ  
    std::string formatted_general = std::format("{:.2g}", number);  
    std::cout << "General format: " << formatted_general << std::endl;  

    return 0;
}  
