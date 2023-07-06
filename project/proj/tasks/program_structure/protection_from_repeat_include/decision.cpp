#include "hope/hope.h"
#include "result/result.h"
#include "iostream"
#include "iomanip"

int main() {
    int num;
    std::cin >> num;
    std::cout << hope(num) << ' ';
    std::cout << std::fixed << std::setprecision(3) << getResult(num);
}