#include <array>

// init at compile time
constexpr int compute(int v) { return v*v*v; }
constinit int global = compute(10);

// won't work:
// constinit int another = global;

int main() {
    // but allow to change later...
    global = 100;

    // global is not constant!
    // std::array<int, global> arr;
}