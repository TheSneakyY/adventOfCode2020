#include <iostream>
#include <string>

int main() {
    int minNumber, maxNumber;
    int counter = 0;
    char letter;
    char password[100];
    std::string tempPassword;
    int validPasswords = 0;
    while (scanf("%d-%d %c: %s", &minNumber, &maxNumber, &letter, &password)) {
        tempPassword.assign(password);
        for (char i : tempPassword) {
            if (letter == i) {
                ++counter;
            }
        }
        if (minNumber <= counter && counter <= maxNumber) {
            ++validPasswords;
        }
        counter = 0;   
    }
    std::cout << validPasswords << std::endl;
    return 0;
}
