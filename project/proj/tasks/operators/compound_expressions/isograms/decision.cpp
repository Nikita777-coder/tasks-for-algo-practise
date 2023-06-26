#include "iostream"

bool isIsogram(const std::string &str) {
    int letter_counter[26] = {0};

    for (char letter : str) {
        int index;

        if (letter > 96 && letter < 123) {
            index = letter - 'a';
        } else {
            index = letter - 'A';
        }

        if (letter_counter[index]) {
            return false;
        }

        letter_counter[index]++;
    }

    return true;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << std::boolalpha << isIsogram(s);
}
