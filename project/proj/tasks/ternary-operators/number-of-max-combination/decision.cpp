#include "iostream"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int res1 = a + b + c, res2 = a + b * c, res3 = (a + b) * c, res4 = a * (b + c), res5 = a * b * c;
    int max = std::max(res1, std::max(res2, std::max(res3, std::max(res4, res5))));

    std::cout << (max == res1 ? 1 : max == res2 ? 2 : max == res3 ? 3 : max == res4 ? 4 : 5);
}