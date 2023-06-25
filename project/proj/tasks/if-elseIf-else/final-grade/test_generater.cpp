#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/if-elseIf-else/final-grade/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_ex_first(20, 50), dis_ex_second(20, 100);
std::uniform_int_distribution<int> dis_proj(0, 15);

int getFinalScore(int ex, int proj) {
    if (ex > 90 || proj > 10) {
        return 100;
    } else if (ex > 75 && proj >= 5) {
        return 90;
    } else if (ex > 50 && proj >= 2) {
        return 75;
    } else if (ex > 25 && proj >= 1) {
        return 50;
    } else {
        return 0;
    }
}

void fileSimpleTestsWriter(int count_of_tasks, bool is_second) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        int ex, proj = dis_proj(rng);
        if (is_second) {
            ex = dis_ex_second(rng);
        } else {
            ex = dis_ex_first(rng);
        }

        ofstream.open(const_path + std::to_string(i));
        ofstream << ex << ' ' << proj;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getFinalScore(ex, proj);
        ofstream.close();
    }
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 100 << ' ' << 12;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(100, 12);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 55 << ' ' << 3;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(55, 3);
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(10, false);
    fileSimpleTestsWriter(10, true);

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 0 << ' ' << 11;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(0, 11);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 0 << ' ' << 10;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(0, 10);
    ofstream.close();

    // 3
    ofstream.open(const_path + std::to_string(i));
    ofstream << 76 << ' ' << 5;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(76, 5);
    ofstream.close();

    // 4
    ofstream.open(const_path + std::to_string(i));
    ofstream << 75 << ' ' << 5;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getFinalScore(75, 5);
    ofstream.close();
}
