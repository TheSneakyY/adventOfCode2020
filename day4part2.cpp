#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <functional>
#include <regex>

bool validatePassport(const std::string &passport) {
    std::istringstream ss(passport);
    char key[100];
    char value[100];
    std::string token;
    std::map<std::string, std::string> tokenMap = {};
    std::map<std::string, std::function<bool(const std::string &)>> validRequiredKeys = {
            {"byr", [](const std::string &tokenMapValue) {
                int tokenMapValueInt = std::stoi(tokenMapValue);
                return tokenMapValue.size() == 4 and tokenMapValueInt >= 1920 and tokenMapValueInt <= 2002;
            }},
            {"iyr", [](const std::string &tokenMapValue) {
                int tokenMapValueInt = std::stoi(tokenMapValue);
                return tokenMapValue.size() == 4 and tokenMapValueInt >= 2010 and tokenMapValueInt <= 2020;
            }},
            {"eyr", [](const std::string &tokenMapValue) {
                int tokenMapValueInt = std::stoi(tokenMapValue);
                return tokenMapValue.size() == 4 and tokenMapValueInt >= 2020 and tokenMapValueInt <= 2030;
            }},
            {"hgt", [](const std::string &tokenMapValue) {
                std::istringstream ss(tokenMapValue);
                int value;
                std::string unit;
                ss >> value;
                ss >> unit;
                if (unit == "cm") {
                    return value >= 150 and value <= 193;
                } else if (unit == "in") {
                    return value >= 59 and value <= 76;
                }
                return false;
            }},
            {"hcl", [](const std::string &tokenMapValue) {
                std::smatch m;
                return std::regex_match(tokenMapValue, m, std::regex("#[a-f0-9]{6}"));
            }},
            {"ecl", [](const std::string &tokenMapValue) {
                std::smatch m;
                return std::regex_match(tokenMapValue, m, std::regex("(amb|blu|brn|gry|grn|hzl|oth)"));
            }},
            {"pid", [](const std::string &tokenMapValue) {
                std::smatch m;
                return std::regex_match(tokenMapValue, m, std::regex("[0-9]{9}"));
            }}
    };

    while (ss >> token) {
        memset(key, 0, 100);
        memset(value, 0, 100);
        sscanf(token.c_str(), "%100[^:]:%100s", key, value);
        tokenMap[key] = value;
    }
    return std::all_of(validRequiredKeys.cbegin(), validRequiredKeys.cend(), [&tokenMap](const auto &x) {
        return tokenMap.find(x.first) != tokenMap.cend() and x.second(tokenMap[x.first]);
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