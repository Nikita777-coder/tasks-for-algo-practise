#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/min_and_max/min_num/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(0, 1000000);
std::uniform_int_distribution<int64_t> dis_num(-2000000000000, 1000000000000);

int64_t getMin(int n, const std::vector<int64_t> &nums) {
    int64_t min = INT64_MAX;

    for (int j = 0; j < n; ++j) {
        min = std::min(nums[j], min);
    }

    if (min == INT64_MAX) {
        min = 0;
    }

    return min;
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int64_t> nums(100000);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';

        for (int k = 0; k < n; ++k) {
            int64_t num = dis_num(rng);
            ofstream << num << ' ';
            nums[k] = num;
        }

        ofstream.close();

        ofstream.open(const_path + std::to_string(i++) + ".a");
        ofstream << getMin(n, nums);
        ofstream.close();

        nums.clear();
    }
}

void limitTest(bool negative) {
    std::vector<int64_t> nums(100000);
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
    ofstream << getMin(n, nums);
    ofstream.close();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << -5 << ' ' << 6;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getMin(2, {-5, 6});
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getMin(4, {1, 2, 3, 4});
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 0 << '\n';
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    ofstream << getMin(0, {});
    ofstream.close();

    // 2
    limitTest(false);

    // 3
    limitTest(true);
}