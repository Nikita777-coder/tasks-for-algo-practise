#include "iostream"
#include "vector"

int main() {
    int n;
    int first_max = INT32_MIN, second_max = INT32_MIN;
    std::cin >> n;
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    int i = 0, j = n;

    while (i < j) {
        int m1 = std::max(vec[i], vec[j]);

        if (m1 > first_max) {
            if (first_max != second_max) {
                second_max = first_max;
            }

            first_max = m1;
        } else if (m1 > second_max && m1 != first_max) {
            second_max = m1;
        }

        ++i;
    }

    std::cout << first_max << ' ' << second_max;
}