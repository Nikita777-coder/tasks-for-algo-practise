#include "iostream"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int res1 = a + b + c, res2 = a + b * c, res3 = (a + b) * c, res4 = a * (b + c), res5 = a * b * c;
    int max = std::max(res1, std::max(res2, std::max(res3, std::max(res4, res5))));

    if (max == res1) {
        std::cout << 1;
    } else if (max == res2) {
        std::cout << 2;
    } else if (max == res3) {
        std::cout << 3;
    } else if (max == res4) {
        std::cout << 4;
    } else {
        std::cout << 5;
    }
}