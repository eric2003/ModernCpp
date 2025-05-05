import std;

int main() {
    std::vector v1{ 11, 22, 33, 44 };
    std::vector v2{ 11, 22 };
    std::println( "{}", std::ranges::starts_with( v1, v2 ) );
    std::println( "{}", std::ranges::ends_with( v1, v2 ) );
    return 0;
}

