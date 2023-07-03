#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 10000;
std::string const_path = "../tasks/linear_alghorithms/elemnt_occur_more_half_other_even_occur/element_which_occurence_only_once/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(2, maxN);
std::uniform_int_distribution<int> dis_num(0, 1);

char getCode(int code) {
    if (code == 1) {
        return 'm';
    } else {
        return 'g';
    }
}

void getChild(int n, const std::vector<char> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    int b = 0;

    for (int ii = 0; ii < n - 1; ++ii) {
        if (nums[ii] == 'm') {
            b++;
        } else {
            b--;
        }
    }

    if (b > 0) {
        ofstream << "Мальчик";
    } else {
        ofstream << "Девочка";
    }

    ofstream.close();
}

int getOdd(int num) {
    return num + (1 - num % 2);
}

int getEven(int num) {
    return num + num % 2;
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<char> nums(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = getEven(dis_n(rng));
        ofstream << n << '\n';
        nums.assign(n, 0);

        int lucky_or_unlucky = dis_num(rng);
        int count = getOdd(n / 2);

        for (int k = 0; k < count; ++k) {
            nums[k] = getCode(lucky_or_unlucky);
            ofstream << nums[k] << ' ';
        }

        for (int k = count; k < n; ++k) {
            nums[k] = getCode(1 - lucky_or_unlucky);
            ofstream << nums[k] << ' ';
        }

        ofstream.close();
        getChild(n, nums);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<char> nums(maxN);
    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 2;
    }

    ofstream << n << '\n';

    int lucky_or_unlucky = dis_num(rng);
    int count = getOdd(n / 2);

    for (int k = 0; k < count; ++k) {
        nums[k] = getCode(lucky_or_unlucky);
        ofstream << nums[k] << ' ';
    }

    for (int k = count; k < n; ++k) {
        nums[k] = getCode(1 - lucky_or_unlucky);
        ofstream << nums[k] << ' ';
    }

    ofstream.close();
    getChild(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 'm' << ' ' << 'm' << ' ' << 'g';
    ofstream.close();
    getChild(4, {'m', 'm', 'g'});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 6 << '\n' << 'g' << ' ' << 'g' << ' ' << 'g' << ' ' << 'm' << ' ' << 'm';
    ofstream.close();
    getChild(6, {'g', 'g', 'g', 'm', 'm'});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}