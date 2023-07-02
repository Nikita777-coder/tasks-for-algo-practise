#include "iostream"

int main() {
    int n;
    std::cin >> n;
    int b = 0;

    for (int i = 0; i < n; ++i) {
        int el;
        std::cin >> el;
        b ^= el;
    }

    std::cout << b;
}
