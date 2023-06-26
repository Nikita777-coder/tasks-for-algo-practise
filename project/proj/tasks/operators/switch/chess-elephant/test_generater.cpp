#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/switch/chess-elephant/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis(1, 8);

std::string getVerdict(int a1, int b1, int a2, int b2) {
    if (abs(a2 - a1) == abs(b2 - b1)) {
        switch (abs(a2 - a1) + abs(b2 - b1)) {
            case 0:
                return std::to_string(0);
            case 2:
                return std::to_string(1);
            case 4:
                return std::to_string(2);
            case 6:
                return std::to_string(3);
            case 8:
                return std::to_string(4);
            case 10:
                return std::to_string(5);
            case 12:
                return std::to_string(6);
            case 14:
                return std::to_string(7);
            default:
                return "NO";
        }
    } else {
        return "NO";
    }
}

void fileSimpleTestsWriter(int count_of_tasks) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        int a1 = dis(rng), b1 = dis(rng), a2 = dis(rng), b2 = dis(rng);
        ofstream.open(const_path + std::to_string(i));
        ofstream << a1 << '\n' << b1 << '\n' << a2 << '\n' << b2;
        ofstream.close();
        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getVerdict(a1, b1, a2, b2);
        ofstream.close();
    }
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 4 << '\n' << 5 << '\n' << 5;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(4, 4, 5, 5);
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 1 << '\n' << 2 << '\n' << 3 << '\n' << 10;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getVerdict(1, 2, 3, 10);
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);
}

