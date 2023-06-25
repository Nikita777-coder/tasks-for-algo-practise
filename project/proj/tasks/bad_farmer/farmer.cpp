#include "iostream"

int main() {
    int weight;
    std::string color;
    std::cin >> weight >> color;

    if (weight > 200 && weight < 450) {
        std::cout << "to " << (color == "red" ? "green" : "red") << " basket";
        return 0;
    }

    std::cout << "not norm";
}