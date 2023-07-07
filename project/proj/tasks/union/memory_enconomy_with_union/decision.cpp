#include "iostream"
#include "iomanip"

union ToString {
    int val;
    double v;

    [[nodiscard]] std::string intToString() const {
        return "int_value = " + std::to_string(val);
    }

    std::string doubleToString() const {
        return "double_value = ";
    }
};

int main() {
    int n;
    std::cin >> n;
    ToString toString {};

    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;

        if (num == static_cast<int>(num)) {
            toString.val = static_cast<int>(num);
            std::cout << toString.intToString();
        } else {
            toString.v = num;
            std::cout << toString.doubleToString() << std::fixed << std::setprecision(7) << toString.v;
        }

        std::cout << '\n';
    }
}
