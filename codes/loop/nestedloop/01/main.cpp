#include <iostream>  
#include <vector>  

void nestedLoop(const std::vector<int>& limits, int depth = 0, std::vector<int> indices = {}) 
{  
    // ��������������ǰ��ȵ������ƵĴ�С����ӡ��ǰ����  
    if (depth == limits.size()) {  
        for (int index : indices) {  
            std::cout << index << " ";  
        }  
        std::cout << std::endl;  
        return;  
    }  

    // ��ǰ��ȵ�ѭ��  
    for (int i = 0; i < limits[depth]; ++i) {  
        indices.push_back(i); // ��ӵ�ǰ����  
        nestedLoop(limits, depth + 1, indices); // �ݹ������һ�����  
        indices.pop_back(); // �Ƴ���ǰ����������  
    }  
}  

int main(int argc, char* argv[])
{
    int numLoops;  
    std::cout << "Enter the number of nested loops: ";  
    std::cin >> numLoops;  

    std::vector<int> limits(numLoops);  
    for (int i = 0; i < numLoops; ++i) {  
        std::cout << "Enter limit for loop " << i + 1 << ": ";  
        std::cin >> limits[i]; // ����ÿ��ѭ��������  
    }  

    nestedLoop(limits); // ��ʼ�ݹ�����Ƕ��ѭ��  

    return 0;  
}  
