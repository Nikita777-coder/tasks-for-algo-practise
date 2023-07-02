#include "iostream"
#include "vector"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 1; i < n; ++i) {
        int max_sum = INT32_MIN;

        for (int j = 0; j < n; ++j) {
            for (int k = j + i; k < n; ++k) {
                int sum = arr[j] + arr[k];

                if (sum % 2) {
                    max_sum = std::max(max_sum, sum);
                }
            }
        }

        if (max_sum == INT32_MIN) {
            max_sum = 0;
        }

        std::cout << max_sum << '\n';
    }
}