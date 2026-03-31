#include <fstream>
#include <iostream>
#include <cstring>
#include <regex>
#include <cstdint>

int main() {
    std::string filename;
    std::regex c_pattern = std::regex("^(/*\\w*_*)+.c$");
    std::cout << "Please enter filename: ";
    std::cin >> filename;
    if (std::regex_match(filename, c_pattern)) {
        std::ifstream in = std::ifstream(filename);
        
        if (in) {
            uint64_t opening_brackets = 0, closing_brackets = 0;
            char i;
            while(!in.eof()) {
                in >> i;
                switch (i) {
                    case '{': {
                        opening_brackets++;
                        break;
                    };
                    case '}': {
                        closing_brackets++;
                        break;
                    }
                }
                i = ' ';
            }

            std::ofstream out = std::ofstream("output.txt");
            out << "opening brackets: " << opening_brackets << '\n';
            out << "closing brackets: " << closing_brackets << '\n';
            std::cout << "opening brackets: " << opening_brackets << '\n';
            std::cout << "closing brackets: " << closing_brackets << '\n';

            in.close();
            out.close();
        } else {
            std::cout << "Error: the file is not open\n";
            return -1;
        }
    } else {
        std::cout << "Error: incorrect file name\n";
    }

    return 0;
}