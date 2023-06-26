#include "iostream"

int main() {
    int weight;
    std::cin >> weight;

    switch (weight) {
        case 100:
            std::cout << "light";
            break;
        case 350:
            std::cout << "norm";
            break;
        case 600:
            std::cout << "heavy";
            break;
    }
}