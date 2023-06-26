#include "iostream"

int main() {
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;

    if (abs(a2 - a1) == abs(b2 - b1)) {
        switch (abs(a2 - a1) + abs(b2 - b1)) {
            case 0:
                std::cout << 0;
                break;
            case 2:
                std::cout << 1;
                break;
            case 4:
                std::cout << 2;
                break;
            case 6:
                std::cout << 3;
                break;
            case 8:
                std::cout << 4;
                break;
            case 10:
                std::cout << 5;
                break;
            case 12:
                std::cout << 6;
                break;
            case 14:
                std::cout << 7;
                break;
            default:
                std::cout << "NO";
                break;
        }
    } else {
        std::cout << "NO";
    }
}