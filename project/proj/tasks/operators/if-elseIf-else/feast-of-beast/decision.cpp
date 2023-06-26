#include "iostream"

int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    if (*s1.begin() == *s2.begin() && s1.back() == s2.back()) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}
