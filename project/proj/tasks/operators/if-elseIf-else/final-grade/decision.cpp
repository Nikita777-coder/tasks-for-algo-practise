#include "iostream"

int main() {
    int ex, proj;
    std::cin >> ex >> proj;

    if (ex > 90 || proj > 10) {
        std::cout << 100;
    } else if (ex > 75 && proj >= 5) {
        std::cout << 90;
    } else if (ex > 50 && proj >= 2) {
        std::cout << 75;
    } else if (ex > 25 && proj >= 1) {
        std::cout << 50;
    } else {
        std::cout << 0;
    }
}
