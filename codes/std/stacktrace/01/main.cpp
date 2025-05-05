import std;

int main() {
    auto trace = std::stacktrace::current();
    std::cout << std::to_string( trace ) << "\n";
    return 0;
}