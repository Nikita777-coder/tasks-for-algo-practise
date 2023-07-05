#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 14;
std::string const_path = "../tasks/program_structure/header_file/tests/0";

void getNFuct(uint32_t n) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    uint64_t res = 1;

    for (uint32_t i = 1; i <= n; ++i) {
        res *= i;
    }

    ofstream << res;

    ofstream.close();
}

void fileSimpleTestsWriter() {
    std::vector<int> nums(maxN);

    for (int j = 0; j <= 14; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        ofstream << j;

        ofstream.close();
        getNFuct(j);
        nums.clear();
    }
}

int main() {
    fileSimpleTestsWriter();
}

