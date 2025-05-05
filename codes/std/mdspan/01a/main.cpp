#include <array>
#include <mdspan>
#include <iostream>

int main()
{
    // 1D data
    std::array<char, 24> aData;
    for (size_t i = 0; i < aData.size(); ++i)
        aData[i] = 'a' + i;

    // 2D view as matrix
    std::mdspan matrix(aData.data(), 4, 6);

    // output matrix
    for (size_t i = 0; i != matrix.extent(0); ++i)
    {
        for (size_t j = 0; j != matrix.extent(1); ++j)
            std::cout << matrix[i, j] << " ";
        std::cout << "\n";
    }
}