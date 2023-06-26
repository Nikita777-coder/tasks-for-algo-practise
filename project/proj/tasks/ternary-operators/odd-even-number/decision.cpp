#include "iostream"

int main() {
    int num;
    std::cin >> num;
    std::cout << (num % 2 ? "Odd" : "Even");
}
