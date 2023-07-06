#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 100000000;
std::string const_path = "../tasks/program_structure/preprocessing_directives/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(-maxN, maxN);
std::uniform_int_distribution<int> dis_small_n(-9, 47);

void getOut(int n) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    if (n < 38 && n > 1) {
#ifndef UB
        ofstream << "37.58 km/h\n";
#define UB
#else
        ofstream << "Поехали!\n";
        #define UG
#endif
    }

    if (n > 38 && n < 5000000) {
#ifndef UG
        ofstream << "Поехали!\n";
#define UG
#else
        ofstream << "37.58 km/h\n";
#define UB
#endif
    }

#if defined(UG) && defined(UB)
    ofstream << "что-то пошло не так";
#endif

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks, bool small) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n;

        if (!small) {
            n = dis_n(rng);
        } else {
            n = dis_small_n(rng);
        }

        ofstream << n;

        ofstream.close();
        getOut(n);
    }
}

void limitTest(int num) {
    ofstream.open(const_path + std::to_string(i));
    ofstream << num;

    ofstream.close();
    getOut(num);
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2;
    ofstream.close();
    getOut(2);

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 39;
    ofstream.close();
    getOut(39);

    /* random tests */
    fileSimpleTestsWriter(10, true);
    fileSimpleTestsWriter(10, false);

    /* limit tests */
    limitTest(38);
    limitTest(1);
    limitTest(5000000);
    limitTest(maxN);
    limitTest(-maxN);
}

