#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string row;
    unsigned int pointOnRow = 0;
    char hit = '#';
    int treesHitCounter = 0;
    std::ifstream fp("/mnt/h/Coding/CLion/adventOfCode/day3Input.txt");
    if (!fp) {
        std::cerr << "Cant open file" << std::endl;
        return 1;
    };
    while (fp >> row) {
        if (row[pointOnRow] == hit) {
            ++treesHitCounter;
        }
        pointOnRow = (pointOnRow + 3) % row.size();
    }
    std::cout << treesHitCounter << std::endl;
    return 0;
}