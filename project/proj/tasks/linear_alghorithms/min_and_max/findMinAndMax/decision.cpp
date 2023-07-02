#include "iostream"
#include "iomanip"

int main() {
    double min = INT64_MAX, max = INT64_MIN;
    double num;

    while (std::cin >> num) {
        if (num < min) {
            min = num;
        }

        if (num > max) {
            max = num;
        }
    }

    if (min == INT64_MAX && max == INT64_MIN) {
        min = 0;
        max = 0;
    }

    std::cout << std::fixed << std::setprecision(3) << min << ' ' << max;
}
