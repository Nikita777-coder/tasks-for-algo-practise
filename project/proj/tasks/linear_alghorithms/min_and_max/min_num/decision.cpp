#include "iostream"

int main() {
    int n;
    std::cin >> n;
    int64_t min = INT64_MAX;

    for (int i = 0; i < n; ++i) {
        int64_t el;
        std::cin >> el;
        min = std::min(el, min);
    }

    if (min == INT64_MAX) {
        min = 0;
    }

    std::cout << min;
}
