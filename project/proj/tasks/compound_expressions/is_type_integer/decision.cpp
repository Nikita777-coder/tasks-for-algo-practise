#include "iostream"

int main() {
    std::string type;
    std::cin >> type;

    if (type == "bool" || type == "short" || type == "int" || type == "long" || type == "char") {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}
