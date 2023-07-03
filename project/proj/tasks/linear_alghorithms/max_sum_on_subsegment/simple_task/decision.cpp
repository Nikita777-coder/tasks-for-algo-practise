#include <iostream>

int main() {
    int n;
    int64_t num;
    std::cin >> n;
    std::cin >> num;
    int64_t max_current_sum = num, max_global_sum = num;

    for (int i = 0; i < n - 1; ++i) {
        std::cin >> num;
        max_current_sum = std::max(num, max_current_sum + num);
        max_global_sum = std::max(max_current_sum, max_global_sum);
    }

    std::cout << max_global_sum << '\n';
}
