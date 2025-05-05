#include <array>
#include <cstdlib>

struct Point {
    int x { 0 };
    int y { 0 };

    constexpr int distX(const Point& other) const { return std::abs(x - other.x); }
};

int main() {
    constexpr Point a { 0, 1 };
    constexpr Point b { 10, 11 };
    static_assert(a.distX(b) == 10);

    // but also at runtime:
    Point c { 100, 1 };
    Point d { 10, 11 };
    return c.distX(d);
}