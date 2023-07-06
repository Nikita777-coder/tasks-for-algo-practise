#include "iostream"

int main() {
    int n;
    std::cin >> n;

    if (n < 38 && n > 1) {
#ifndef UB
        std::cout << "37.58 km/h\n";
#define UB
#else
        std::cout << "Поехали!\n";
        #define UG
#endif
    }

    if (n > 38 && n < 5000000) {
#ifndef UG
        std::cout << "Поехали!\n";
#define UG
#else
        std::cout << "37.58 km/h\n";
#define UB
#endif
    }

#if defined(UG) && defined(UB)
    std::cout << "что-то пошло не так";
#endif
}