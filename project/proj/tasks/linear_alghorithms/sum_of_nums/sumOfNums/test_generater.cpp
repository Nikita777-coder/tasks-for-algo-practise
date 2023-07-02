#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/sum_of_nums/sumOfNums/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(0, 100000);
std::uniform_int_distribution<int> dis_num(-1000000000, 1000000000);

int64_t getSum(int n, const std::vector<int> &nums) {
    int64_t sum = 0;

    for (int j = 0; j < n; ++j) {
        sum += nums[j];
    }

    return sum;
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int> nums(100000);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';

        for (int k = 0; k < n; ++k) {
            int num = dis_num(rng);
            ofstream << num << ' ';
            nums[k] = num;
        }

        ofstream.close();

        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getSum(n, nums);
        ofstream.close();

        nums.clear();
    }
}

void limitTest(bool negative) {
    std::vector<int> nums(100000);
    ofstream.open(const_path + std::to_string(i));

    int n = 100000;
    ofstream << n << '\n';

    for (int k = 0; k < n; ++k) {
        int num;

        if (!negative) {
            num = 1000000000;
        } else {
            num = -1000000000;
        }

        ofstream << num << ' ';
        nums[k] = num;
    }

    ofstream.close();

    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getSum(n, nums);
    ofstream.close();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << -5 << ' ' << 6;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getSum(2, {-5, 6});
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getSum(4, {1, 2, 3, 4});
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 0 << '\n';
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getSum(0, {});
    ofstream.close();

    // 2
    limitTest(false);

    // 3
    limitTest(true);
}


