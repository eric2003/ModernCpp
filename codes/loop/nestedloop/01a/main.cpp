#include <iostream>  
#include <vector>  

void nestedLoop(const std::vector<int>& limits, int depth = 0, std::vector<int> indices = {}) 
{  
    // 基本情况：如果当前深度等于限制的大小，打印当前索引  
    if (depth == limits.size()) {  
        for (int index : indices) {  
            std::cout << index << " ";  
        }  
        std::cout << std::endl;  
        return;  
    }  

    // 当前深度的循环  
    for (int i = 0; i < limits[depth]; ++i) {  
        indices.push_back(i); // 添加当前索引  
        nestedLoop(limits, depth + 1, indices); // 递归调用下一个深度  
        indices.pop_back(); // 移除当前索引，回溯  
    }  
}  

int main(int argc, char* argv[])
{
    std::vector<int> limits;  
    int ni = 2;
    int nj = 3;
    limits.push_back( ni );
    limits.push_back( nj );

    nestedLoop(limits); // 开始递归生成嵌套循环  

    return 0;  
}  
