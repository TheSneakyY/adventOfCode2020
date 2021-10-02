#include <iostream>
#include <string>

int main() {
    int firstIndex, secondIndex;

    char letter;
    char password[100];
    std::string tempPassword;
    int validPasswords = 0;
    while (scanf("%d-%d %c: %s", &firstIndex, &secondIndex, &letter, &password)) {
        tempPassword.assign(password);
        if (tempPassword[firstIndex - 1] == letter ^ tempPassword[secondIndex - 1] == letter) {
            ++validPasswords;
        }
    }
    std::cout << validPasswords << std::endl;
    return 0;
}
