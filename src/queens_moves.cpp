#include <cstdint>
#include <iostream>
#include <utility>

constexpr uint16_t MAX_COORDINATE = 8;
constexpr uint16_t MIN_COORDINATE = 0;

bool between(int16_t target, int16_t l, int16_t h) {
    return target >= l && target <= h;
}

bool valid_step(int16_t start_x, int16_t start_y, int16_t cur_x, int16_t cur_y) {
    int16_t dif_x = abs(start_x - cur_x);
    int16_t dif_y = abs(start_y - cur_y);
    return dif_x == dif_y || (dif_x == 0 && dif_y != 0) || (dif_x != 0 && dif_y ==0);
}

int main() {
    int16_t start_x, start_y, cur_x, cur_y;

    std::cout << "For exit press 'Ctrl + C'\n";
    std::cout << "Please enter start position: ";
    std::cin >> start_x >> start_y;

    while (true) {
        std::cout << "Please enter current position: ";
        std::cin >> cur_x >> cur_y;

        if (between(cur_x, MIN_COORDINATE, MAX_COORDINATE) && between(cur_y, MIN_COORDINATE, MAX_COORDINATE)) {
            std::cout << (valid_step(start_x, start_y, cur_x, cur_y) ? "Yes" : "No") << '\n';
            start_x = cur_x;
            start_y = cur_y;
            cur_x = 0;
            cur_y = 0;

            std::cout << "New start position: (" << start_x << " : " << start_y << ")\n";
    
        } else {
            std::cout << "Error: invalid coordinate\n";
        }
    }

    return 0;
}