#include "iostream"
#include "fstream"
#include "random"

union Union {
    char code;
    char ch;
};

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/union/researching_values_of_union/char_and_it_code/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_r(0, 1);
std::uniform_int_distribution<int> dis_n(1, 255);
std::uniform_int_distribution<int> dis_ch(48, 122);

void getCodeAndChar(const std::string &s, char ch = 0, int code = 0) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    Union anUnion;

    if (s == "char") {
        anUnion.ch = ch;
    } else {
        anUnion.code = code;
    }

    ofstream << static_cast<int>(anUnion.code) << '-' << anUnion.ch;

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int r = dis_r(rng);
        int code;
        char c;
        std::string s;

        if (r == 0) {
            ofstream << "code\n";
            s = "code";
            code = dis_n(rng);
            ofstream << code;
        } else {
            ofstream << "char\n";
            s = "char";
            c = static_cast<char>(dis_ch(rng));
            ofstream << c;
        }

        ofstream.close();
        getCodeAndChar(s, c, code);
    }
}

void limitTest(bool min) {
    ofstream.open(const_path + std::to_string(i));
    int r = dis_r(rng);
    int code;
    char c;
    std::string s;

    if (r == 0) {
        ofstream << "code\n";
        s = "code";

        if (min) {
            code = 1;
        } else {
            code = 255;
        }
    } else {
        ofstream << "char\n";
        s = "char";

        if (min) {
            c = '0';
        } else {
            c = 'z';
        }
    }

    ofstream.close();
    getCodeAndChar(s, c, code);
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << "code" << '\n' << 23;
    ofstream.close();
    getCodeAndChar("code", 0, 23);

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << "char\n" << 'S';
    ofstream.close();
    getCodeAndChar("char", 'S');

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}


