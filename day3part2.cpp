#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string row;

    unsigned int pointOnRow1 = 0;
    unsigned int pointOnRow3 = 0;
    unsigned int pointOnRow5 = 0;
    unsigned int pointOnRow7 = 0;
    unsigned int pointOnRow12 = 0;
    char hit = '#';
    long int treesHitCounter1 = 0;
    long int treesHitCounter3 = 0;
    long int treesHitCounter5 = 0;
    long int treesHitCounter7 = 0;
    long int treesHitCounter12 = 0;
    long int rowNumber = 0;
    std::ifstream fp("/mnt/h/Coding/CLion/adventOfCode/day3Input.txt");
    if (!fp) {
        std::cerr << "Cant open file" << std::endl;
        return 1;
    }
    while (fp >> row) {
        if (row[pointOnRow1] == hit) {
            ++treesHitCounter1;
        }

        if (row[pointOnRow3] == hit) {
            ++treesHitCounter3;
        }

        if (row[pointOnRow5] == hit) {
            ++treesHitCounter5;
        }

        if (row[pointOnRow7] == hit) {
            ++treesHitCounter7;
        }

        pointOnRow1 = (pointOnRow1 + 1) % row.size();
        pointOnRow3 = (pointOnRow3 + 3) % row.size();
        pointOnRow5 = (pointOnRow5 + 5) % row.size();
        pointOnRow7 = (pointOnRow7 + 7) % row.size();
        if (rowNumber++ % 2 == 0) {
            if (row[pointOnRow12] == hit) {
                ++treesHitCounter12;
            }
            pointOnRow12 = (pointOnRow12 + 1) % row.size();
        }

    }
    std::cout << treesHitCounter1 << std::endl;
    std::cout << treesHitCounter3 << std::endl;
    std::cout << treesHitCounter5 << std::endl;
    std::cout << treesHitCounter7 << std::endl;
    std::cout << treesHitCounter12 << std::endl;
    std::cout << treesHitCounter1 * treesHitCounter3 * treesHitCounter5 * treesHitCounter7 * treesHitCounter12
              << std::endl;
    return 0;
}
