#include <iostream>
#include <cstdint>
#include <cmath>

int main() {
    std::cout << "Please enter number: ";
    uint64_t number;
    std::cin >> number;

    auto digits = log10(static_cast<double>(number));
    for (uint64_t i = 0; i < digits; i++) {
        auto right = number / static_cast<uint64_t>(pow(10,i)) % 10;
        auto left = number / static_cast<uint64_t>(pow(10, static_cast<uint64_t>(digits - i))) % 10;
        if (right != left) {
            std::cout << "не является палиндромом " << right << " : " << left << "\n";
            return 0;
        }
    }

    std::cout << "является палиндромом\n";

    return 0;
}