#include "iostream"
#include "fstream"
#include "random"

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

std::ofstream ofstream;
int i = 1;
int64_t const maxN = 2 * 10e18;
std::string const_path = "../tasks/union/researching_values_of_union/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_bool(0, 1);
std::uniform_int_distribution<int> dis_char(CHAR_MIN, CHAR_MAX);
std::uniform_int_distribution<int> dis_int(INT32_MIN, INT32_MAX);
std::uniform_real_distribution<float> dis_float(INT32_MIN, INT32_MAX);
std::uniform_real_distribution<double> dis_double(-maxN, maxN);
std::uniform_int_distribution<int64_t> dis_long(-maxN, maxN);
std::uniform_int_distribution<uint64_t> dis_uint64(0, maxN);
std::uniform_int_distribution<uint64_t> dis_uint32(0, UINT32_MAX);
std::uniform_int_distribution<uint16_t> dis_uint16(0, UINT16_MAX);

void getAns(bool cond, char ch, int n, float f, double d, int64_t num, uint64_t u_num, uint32_t un, uint16_t sn) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    Union anUnion{};

    for (int i = 0; i < 9; ++i) {
        switch (i) {
            case 0:
                anUnion.cond = cond;
                break;
            case 1:
                anUnion.ch = ch;
                break;
            case 2:
                anUnion.n = n;
                break;
            case 3:
                anUnion.f = f;
                break;
            case 4:
                anUnion.d = d;
                break;
            case 5:
                anUnion.num = num;
                break;
            case 6:
                anUnion.u_num = u_num;
                break;
            case 7:
                anUnion.un = un;
                break;
            case 8:
                anUnion.sn = sn;
                break;
            default:
                break;
        }

        ofstream << anUnion.cond << ' ' << anUnion.ch << ' ' << anUnion.n << ' '<< anUnion.f << ' '
                  << anUnion.d << ' '<< anUnion.num << ' '<< anUnion.u_num << ' ' << anUnion.un << ' ' << anUnion.sn << '\n';
    }

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        bool cond = dis_bool(rng);
        char ch = static_cast<char>(dis_char(rng));
        int n = dis_int(rng);
        float f = dis_float(rng);
        double d = dis_double(rng);
        int64_t num = dis_long(rng);
        uint64_t u_num = dis_uint64(rng);
        uint32_t un = dis_uint32(rng);
        uint16_t sn = dis_uint16(rng);

        ofstream << cond << '\n' << ch << '\n' << n << '\n'<< f << '\n'
                 << d << '\n'<< num << '\n'<< u_num << '\n' << un << '\n' << sn;

        ofstream.close();
        getAns(cond, ch, n, f, d, num, u_num, un, sn);
    }
}

void limitTest(bool min) {
    ofstream.open(const_path + std::to_string(i));
    bool cond;
    char ch;
    int n;
    float f;
    double d;
    int64_t num;
    uint64_t u_num;
    uint32_t un;
    uint16_t sn;

    if (min) {
        cond = false;
        ch = 1;
        n = INT32_MIN;
        f = INT32_MIN;
        d = -maxN;
        num = -maxN;
        u_num = 0;
        un = 0;
        sn = 0;
    } else {
        cond = true;
        ch = static_cast<char>(255);
        n = INT32_MAX;
        f = INT32_MAX;
        d = maxN;
        num = maxN;
        u_num = maxN;
        un = UINT32_MAX;
        sn = UINT16_MAX;
    }

    ofstream << cond << '\n' << ch << '\n' << n << '\n'<< f << '\n'
             << d << '\n'<< num << '\n'<< u_num << '\n' << un << '\n' << sn;

    ofstream.close();
    getAns(cond, ch, n, f, d, num, u_num, un, sn);
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1 << '\n' << 35 << '\n' << 384684 << '\n' << 2384783 << '\n' << -1392389233 << '\n'
            << -239792389 << '\n' << 238783278372 << '\n' << 10 << '\n' << 1000;
    ofstream.close();
    getAns(true, 35, 384684, 2384783, -1392389233, -239792389, 238783278372, 10, 1000);

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1 << '\n' << 2 << '\n' << 3 << '\n' << -83 << '\n' << 4 << '\n' << 5 << '\n' << 6 << '\n' << 8 << '\n' << 9;
    ofstream.close();
    getAns(1, 2, 3, -83, 4, 5, 6, 8, 9);

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

