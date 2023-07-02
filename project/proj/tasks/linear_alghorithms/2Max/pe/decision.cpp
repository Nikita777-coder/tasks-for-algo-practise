#include "iostream"

int main() {
    int64_t first_max = INT64_MIN, second_max = INT64_MIN;
    int count;
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        int el;
        std::cin >> el;

        if (el > first_max) {
            second_max = first_max;
            first_max = el;
        } else if (el > second_max) {
            second_max = el;
        }
    }

    std::cout << first_max << ' ' << second_max;
}
