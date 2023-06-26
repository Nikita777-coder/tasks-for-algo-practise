#include "iostream"
#include "fstream"
#include "random"

int getNumberOfMaxComb(int a, int b, int c) {
    int res1 = a + b + c, res2 = a + b * c, res3 = (a + b) * c, res4 = a * (b + c), res5 = a * b * c;
    int max = std::max(res1, std::max(res2, std::max(res3, std::max(res4, res5))));

    return (max == res1 ? 1 : max == res2 ? 2 : max == res3 ? 3 : max == res4 ? 4 : 5);
}

int main() {
    std::ofstream ofstream;
    int i = 1;
    std::string const_path = "../tasks/ternary-operators/number-of-max-combination/tests/0";
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dis_first(1, 3), dis_second(5, 10), dis_third(1, 100);

    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1 << ' ' << 2 << ' ' << 3;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getNumberOfMaxComb(1, 2, 3);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 3 << ' ' << 3 << ' ' << 3;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getNumberOfMaxComb(3, 3, 3);
    ofstream.close();

    /* common tests with first random data*/
    for (int j = 0; j < 6; ++j) {
        int a = dis_first(rng), b = dis_first(rng), c = dis_first(rng);
        ofstream.open(const_path + std::to_string(i));
        ofstream << a << ' ' << b << ' ' << c;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getNumberOfMaxComb(a, b, c);
        ofstream.close();
    }

    /* common tests with second random data*/
    for (int j = 0; j < 10; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        int a = dis_second(rng), b = dis_second(rng), c = dis_second(rng);
        ofstream.open(const_path + std::to_string(i));
        ofstream << a << ' ' << b << ' ' << c;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getNumberOfMaxComb(a, b, c);
        ofstream.close();
    }

    /* common tests with third random data */
    for (int j = 0; j < 10; ++j) {
        int a = dis_third(rng), b = dis_third(rng), c = dis_third(rng);
        ofstream.open(const_path + std::to_string(i));
        ofstream << a << ' ' << b << ' ' << c;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getNumberOfMaxComb(a, b, c);
        ofstream.close();
    }

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1 << ' ' << 1 << ' ' << 1;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getNumberOfMaxComb(1, 1, 1);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 100 << ' ' << 100 << ' ' << 100;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getNumberOfMaxComb(100, 100, 100);
    ofstream.close();
}
