#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <algorithm>

constexpr double cost = 10.0;
constexpr uint64_t group_capacity = 5;

double calc_ticket_price(const std::vector<uint64_t>& ages) {
    std::vector<uint64_t> temp_ages = ages;
    auto min = std::min_element(temp_ages.begin(), temp_ages.end());
    return cost / 100 * (100 - *min) * group_capacity;
}

int main() {
    std::vector<uint64_t> ages = std::vector<uint64_t>();
    std::cout << "Please enter the age of the 5-person group members\n" \
        "as integers separated by a space:\n";

    for (int i = 0; i < group_capacity; i++) {
        uint64_t age;
        std::cin >> age;
        ages.push_back(age);
    }

    std::cout << calc_ticket_price(ages) << '\n';

    return 0;
}