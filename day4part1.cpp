#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <array>
#include <cstring>

bool validatePassport(const std::string &passport) {
    std::istringstream ss(passport);
    char key[100];
    char value[100];
    std::string token;
    std::map<std::string, std::string> tokenMap = {};
    std::array<std::string, 7> validRequiredKeys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    while (ss >> token) {
        memset(key, 0, 100);
        memset(value, 0, 100);
        sscanf(token.c_str(), "%100[^:]:%100s", key, value);
        tokenMap[key] = value;
    }
    return std::all_of(validRequiredKeys.cbegin(), validRequiredKeys.cend(), [&tokenMap](const auto &x) {
        return tokenMap.find(x) != tokenMap.cend();
    });
}

int main() {
    std::string row;
    std::string rawPassport;
    int validatedPassports = 0;
    std::ifstream fp("/mnt/h/Coding/CLion/adventOfCode/day4Input.txt");
    if (!fp) {
        std::cerr << "Cant open file" << std::endl;
        return 1;
    }
    while (std::getline(fp, row)) {
        if (row.empty()) {
            validatedPassports += validatePassport(rawPassport);
            rawPassport.clear();
        } else {
            rawPassport += row + " ";
        }
    }
    validatedPassports += validatePassport(rawPassport);
    std::cout << std::endl << "Validated passports:" << validatedPassports << std::endl;
    return 0;
}
