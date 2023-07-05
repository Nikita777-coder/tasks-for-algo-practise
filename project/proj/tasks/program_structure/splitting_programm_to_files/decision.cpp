#include "decision.h"

int n;
std::vector<int> array;

int main() {
    std::cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int el;
        std::cin >> el;
        array.emplace_back(el);
    }

    std::cout << getMissedValue();
}
