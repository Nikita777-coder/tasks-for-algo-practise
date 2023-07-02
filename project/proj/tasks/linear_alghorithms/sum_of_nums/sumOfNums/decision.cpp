#include "iostream"

int main() {
    int64_t sum = 0;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int el;
        std::cin >> el;
        sum += el;
    }

    std::cout << sum;
}