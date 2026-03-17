#include <cmath>
#include <iostream>
#include <cstdint>
#include <cstring>
constexpr uint64_t base = 50;

uint64_t enter_count(std::string invitation) {
    uint64_t count;
    std::cout << invitation << ": ";
    std::cin >> count;
    return count;
}

uint64_t calculate_available_number(uint64_t count) {
    return base - count % base;
}

int main() {
    auto count = enter_count("Пожалуйста, введите количество пассажиров на остановке");
    std::cout << "Осталось свободных мест: " << calculate_available_number(count) << std::endl;

    return 0;
}