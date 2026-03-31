#include <fstream>
#include <iostream>
#include <array>
#include <cstdint>
#include <regex>
#include <cstring>
#include <algorithm>

constexpr uint64_t PHONE_NUMBER_LEN = 18;

/*

    Напишите программу которая сортирует записи в файле в порядке возрастания номера телефона. 
    В текстовом файле находятся записи о номерах телефонов. 
    В каждой строке записана информация: номер телефона, ФИО, адрес.

*/

int main() {
    std::string filename;
    std::regex name_pattern = std::regex("^(/*\\w*_*)+.txt$");
    std::cout << "Please enter filename: ";
    std::cin >> filename;

    if (std::regex_match(filename, name_pattern)) {
        std::ifstream in = std::ifstream(filename);

        if (in.is_open()) {
            std::vector<std::pair<uint64_t, std::string>> records = std::vector<std::pair<uint64_t, std::string>>();
            std::vector<std::pair<std::string, uint64_t>> numbers = std::vector<std::pair<std::string, uint64_t>>();
            std::string string;

            for (uint64_t i = 0; !in.eof(); i++) {
                std::getline(in, string);
                numbers.emplace_back(std::pair<std::string, uint64_t>(string.substr(0, PHONE_NUMBER_LEN), i));
                records.emplace_back(std::pair<uint64_t, std::string>(i, string));
            }

            std::sort(numbers.begin(), numbers.end());

            for (auto pair : numbers) {
                std::cout << pair.first << " : " << pair.second << "\n";
            }

            in.close();

            std::ofstream out = std::ofstream(filename);

            for (auto pair : numbers) {
                out << records.at(pair.second).second << '\n';
            }
        
            out.close();
        } else {
            std::cout << "Error: file not opened\n";
        }
    } else {
        std::cout << "Error: incorrect file name\n";
    }
    return 0;
}