#include <iostream>
#include <cstdint>

void countdown(int64_t count) {
    for(int64_t i = count; i >= 1; i--) {
        std::cout << i << std::endl << (i % 5 == 0 ? "Beep\n" : "");
    }
}

int main() {
    int64_t count;
    std::cout << "Please enter a natural number: ";
    std::cin >> count;
    std::fflush(stdin);
    countdown(count);

    return 0;
}