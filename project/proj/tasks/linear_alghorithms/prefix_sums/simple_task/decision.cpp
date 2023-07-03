#include <iostream>

const long MAXn = 1000500;
int n;
int partsum[MAXn];

int main() {
    // 3 строчки для ускорения ввода/вывода
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;

    partsum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int el;
        std::cin >> el;
        partsum[i] = partsum[i - 1] + el;
    }

    int count;
    std::cin >> count;

    for (int j = 0; j < count; ++j) {
        int i;
        std::cin >> i;
        std::cout << partsum[i - 1];
    }

    return 0;
}