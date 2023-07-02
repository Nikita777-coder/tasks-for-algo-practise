#include "iostream"

int main() {
    int n;
    std::cin >> n;
    int64_t sum = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; ++i) {
        int el;
        std::cin >> el;
        sum -= el;
    }

    std::cout << sum;
}
