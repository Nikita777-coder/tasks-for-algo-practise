#include "iostream"

union Union {
    int code;
    char ch;
};

int main() {
    std::string s;
    std::cin >> s;

    Union anUnion;

    if (s == "char") {
        std::cin >> anUnion.ch;
    } else {
        std::cin >> anUnion.code;
    }

    std::cout << anUnion.code << ' ' << anUnion.ch;
}
