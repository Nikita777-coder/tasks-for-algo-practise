#include "iostream"

int main() {
    int n;
    std::cin >> n;
    int min_el = INT32_MAX, max_el = INT32_MIN;
    int sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        int el;
        std::cin >> el;
        sum += el;
        min_el = std::min(el, min_el);
        max_el = std::max(el, max_el);
    }

    std::cout << (min_el + max_el) * n / 2 - sum;
}
