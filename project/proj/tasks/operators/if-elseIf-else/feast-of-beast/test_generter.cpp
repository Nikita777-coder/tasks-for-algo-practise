#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/operators/if-elseIf-else/feast-of-beast/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_ind(0, 26);
std::uniform_int_distribution<int> dis_length(5, 40);
const std::string available_symbols = "abcdefghij klmnopqrstuvwxyz";
std::string s1, s2;

std::string getVerdict() {
    if (*s1.begin() == *s2.begin() && s1.back() == s2.back()) {
        return "true";
    }

    return "false";
}

void fileSimpleTestsWriter(int count_of_tasks, bool true_generate) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        for (int k = 0; k < dis_length(rng); ++k) {
            s1.push_back(available_symbols[dis_ind(rng)]);
        }

        if (true_generate) {
            s2.push_back(*s1.begin());

            for (int k = 0; k < dis_length(rng); ++k) {
                s2.push_back(available_symbols[dis_ind(rng)]);
            }

            s2.push_back(s1.back());
        } else {
            for (int k = 0; k < dis_length(rng); ++k) {
                s2.push_back(available_symbols[dis_ind(rng)]);
            }
        }

        ofstream.open(const_path + std::to_string(i));
        ofstream << s1 << '\n' << s2;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getVerdict();
        ofstream.close();

        s1.clear();
        s2.clear();
    }
}

int main() {
    /* sample tests */
    // 1
    s1 = "great blue heron", s2 = "garlic naan";
    ofstream.open(const_path + std::to_string(i));
    ofstream << s1 << '\n' << s2;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict();
    ofstream.close();

    // 2
    s1 = "chickadee", s2 = "chocolate cakes";
    ofstream.open(const_path + std::to_string(i));
    ofstream << s1 << '\n' << s2;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict();
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(10, false);
    fileSimpleTestsWriter(10, true);
}

