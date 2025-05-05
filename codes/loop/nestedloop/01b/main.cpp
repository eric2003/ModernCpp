#include <iostream>  
#include <vector>  

void nestedLoop(const std::vector<int>& limits, int depth, std::vector<int> &indices, int &icount, std::vector<int> &values)
{  
    int nDim = limits.size();
    if ( depth == nDim )
    {  
        for (int index : indices)
        {  
            std::cout << index << " ";  
        }  
        std::cout << std::endl;  
        return;  
    }  

    // 当前深度的循环  
    int n = limits[ depth ];
    for ( int i = 0; i < n; ++i )
    {  
        indices.push_back(i); // 添加当前索引  
        nestedLoop(limits, depth + 1, indices, icount, values); // 递归调用下一个深度  
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

    int nCount = ni * nj;
    std::vector<int> values(nCount);

    int count = 0;

    for ( int i = 0; i < ni; ++ i )
    {
        for ( int j = 0; j < nj; ++ j )
        {
            int v = i * 100 + j;
            values[count ++] = v;
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> indices = {};
    int icount = 0;

    nestedLoop(limits, 0, indices, icount, values);

    return 0;  
}  
