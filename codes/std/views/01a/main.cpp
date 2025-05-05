import std;

int main() {  
    std::vector<int> data{1,2,3,4,5};

    constexpr auto square = std::views::transform([](int v) { return v * v; });
    for (int v : data | square) {
        std::print( "{} ", v );
    }
    std::println();

    return 0;  
}  

