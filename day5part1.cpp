#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    int tmpSeatId = 0;
    int seatId = 0;
    std::string row;
    std::ifstream fp("../inputs/day5Input.txt");
    if (!fp) {
        std::cerr << "Cant open file" << std::endl;
        return 1;
    }
    while (std::getline(fp, row)) {
        std::cout << "row: " << row << std::endl;
        tmpSeatId = 0;
        for(int i = 0; i < 7; ++i) {
            tmpSeatId |= row[i] == 'F' ? 0 : 1;
            tmpSeatId <<= 1;
        }
        for(int i = 7; i < 10; ++i) {
            tmpSeatId |= row[i] == 'L' ? 0 : 1;
            tmpSeatId <<= 1;
        }
        tmpSeatId >>= 1;
        std::cout << "seatId: " << tmpSeatId << std::endl;
        seatId = tmpSeatId > seatId ? tmpSeatId : seatId;
    }
    std::cout << seatId << std::endl;
}

