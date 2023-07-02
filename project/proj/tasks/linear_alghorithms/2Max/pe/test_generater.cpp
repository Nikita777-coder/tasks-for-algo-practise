#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/2Max/pe/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(2, 100);
std::uniform_int_distribution<int> dis_num(100, 200);

std::pair<int, int> get2Max(int n, const std::vector<int> &nums) {
    int64_t first_max = INT64_MIN, second_max = INT64_MIN;

    for (int ii = 0; ii < n; ++ii) {
        if (nums[ii] > first_max) {
            second_max = first_max;
            first_max = nums[ii];
        } else if (nums[ii] > second_max) {
            second_max = nums[ii];
        }
    }

    return {first_max, second_max};
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
        auto res = get2Max(n, nums);
        ofstream << res.first << ' ' << res.second;
        ofstream.close();

        nums.clear();
    }
}

void limitTest(bool negative) {
    std::vector<int> nums(100);
    ofstream.open(const_path + std::to_string(i));

    int n = 100;

    for (int k = 0; k < n; ++k) {
        int num;

        if (!negative) {
            num = 100;
        } else {
            num = 200;
        }

        ofstream << num << ' ';
        nums[k] = num;
    }

    ofstream.close();

    ofstream.open(const_path + std::to_string(i++) + ".a");
    auto res = get2Max(n, nums);
    ofstream << res.first << ' ' << res.second;
    ofstream.close();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 120 << ' ' << 121;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    auto res = get2Max(2, {120, 121});
    ofstream << res.first << ' ' << res.second;
    ofstream.close();

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 120 << ' ' << 130 << ' ' << 130 << ' ' << 140;
    ofstream.close();
    ofstream.open(const_path + std::to_string(i++) + ".a");
    res = get2Max(4, {120, 130, 130, 140});
    ofstream << res.first << ' ' << res.second;
    ofstream.close();

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    // 1
    limitTest(false);

    // 2
    limitTest(true);
}
