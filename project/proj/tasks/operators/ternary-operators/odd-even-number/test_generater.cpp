#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/operators/ternary-operators/odd-even-number/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis(-2000000, 2000000);

std::string getVerdict(int num) {
    return (num % 2 ? "Odd" : "Even");
}

void fileSimpleTestsWriter(int count_of_tasks) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        int num = dis(rng);
        ofstream.open(const_path + std::to_string(i));
        ofstream << num;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getVerdict(num);
        ofstream.close();
    }
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << -2;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(-2);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 21;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(21);
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << -2000000;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(-2000000);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2000000;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(2000000);
    ofstream.close();
}

