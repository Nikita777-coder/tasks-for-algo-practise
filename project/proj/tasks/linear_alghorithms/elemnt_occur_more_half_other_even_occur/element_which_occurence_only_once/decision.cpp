#include "iostream"

int main() {
    int n;
    std::cin >> n;
    int b = 0;

    for (int i = 0; i < n - 1; ++i) {
        char gen;
        std::cin >> gen;

        if (gen == 'm') {
            b++;
        } else {
            b--;
        }
    }

    if (b > 0) {
        std::cout << "Мальчик";
    } else {
        std::cout << "Девочка";
    }
}
