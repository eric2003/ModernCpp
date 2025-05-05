#include <vector>
#include <print>

int main() {
    std::vector<std::pair<int, int>> v{ {1,2},{3,4} };
    std::println( "{}", v );
    return 0;
}