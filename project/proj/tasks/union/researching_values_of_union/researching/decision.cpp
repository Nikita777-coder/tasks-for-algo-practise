#include "iostream"

union Union {
    bool cond;
    char ch;
    int n;
    float f;
    double d;
    int64_t num;
    uint64_t u_num;
    uint32_t un;
    uint16_t sn;
};

int main() {
    Union anUnion{};

    for (int i = 0; i < 9; ++i) {
        switch (i) {
            case 0:
                std::cin >> anUnion.cond;
                break;
            case 1:
                std::cin >> anUnion.ch;
                break;
            case 2:
                std::cin >> anUnion.n;
                break;
            case 3:
                std::cin >> anUnion.f;
                break;
            case 4:
                std::cin >> anUnion.d;
                break;
            case 5:
                std::cin >> anUnion.num;
                break;
            case 6:
                std::cin >> anUnion.u_num;
                break;
            case 7:
                std::cin >> anUnion.un;
                break;
            case 8:
                std::cin >> anUnion.sn;
                break;
            default:
                break;
        }

        std::cout << anUnion.cond << ' ' << anUnion.ch << ' ' << anUnion.n << ' '<< anUnion.f << ' '
        << anUnion.d << ' '<< anUnion.num << ' '<< anUnion.u_num << ' ' << anUnion.un << ' ' << anUnion.sn << '\n';
    }
}