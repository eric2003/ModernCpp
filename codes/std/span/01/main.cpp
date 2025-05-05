// C++ program to illustrate the use of std::span 
#include <iostream> 
#include <span> 

int main(int argc, char* argv[])
{ 
    int arr[] = { 1, 2, 3, 4, 5 }; 

    // Create a span of int of array 
    std::span<int> span_arr(arr); 

    for (const auto& num : span_arr) { 
        std::cout << num << " "; 
    } 
    return 0; 
}

