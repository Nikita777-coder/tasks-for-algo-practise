#include "iostream"
#include "fstream"
#include "random"
#include "hope.h"
#include "result.h"

std::ofstream ofstream;
int i = 1;
int const maxN = 100000000;
std::string const_path = "../tasks/program_structure/include_directive/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(-maxN, maxN);

void getOut(int n) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    ofstream << hope(n) << ' ';
    ofstream << std::fixed << std::setprecision(3) << getResult(n);

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n;

        n = dis_n(rng);

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
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(maxN);
    limitTest(-maxN);
}

