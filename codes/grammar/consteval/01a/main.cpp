consteval int sum(int a, int b) {
    return a + b;
}

constexpr int sum_c(int a, int b) {
    return a + b;
}

int main() {
    constexpr auto c = sum(100, 100);
    static_assert(c == 200);

    constexpr auto val = 10;
    static_assert(sum(val, val) == 2*val);

    int a = 10;
    int b = sum_c(a, 10); // fine with constexpr function

    int d = sum(a, 10); // error! the value of 'a' is 
                        // not usable in a constant expression
}