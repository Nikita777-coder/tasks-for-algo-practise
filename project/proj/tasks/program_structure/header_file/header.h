#include "iostream"

#ifndef PROJ_HEADER_H
#define PROJ_HEADER_H

uint64_t getFuct(uint32_t n) {
    uint64_t res = 1;

    for (int i = 1; i <= n; ++i) {
        res *= i;
    }

    return res;
}

namespace Console {
    uint32_t n;

    void getNFomUser() {
        std::cin >> n;
    }

    void getNFact() {
        std::cout << getFuct(n);
    }
}

#endif //PROJ_HEADER_H
