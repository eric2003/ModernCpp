#include <iostream>
#include <optional>

int main() {
    std::optional<int> optionalInt;

    if (optionalInt.has_value()) {
        std::cout << "Value is present: " << optionalInt.value() << std::endl;
    } else {
        std::cout << "Value is not set." << std::endl;
    }

    optionalInt = 42;

    if (optionalInt.has_value()) {
        std::cout << "Value is present: " << optionalInt.value() << std::endl;
    } else {
        std::cout << "Value is not set." << std::endl;
    }

    return 0;
}