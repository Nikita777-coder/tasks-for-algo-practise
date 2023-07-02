#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
std::string const_path = "../tasks/linear_alghorithms/max_odd_sum_on_some_distance/max_odd_sum_in_all_distances/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(2, 100);
std::uniform_int_distribution<int> dis_num(-1000000000, 1000000000);

void getMaxSums(int n, const std::vector<int> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    for (int ii = 1; ii < n; ++ii) {
        int max_sum = INT32_MIN;

        for (int j = 0; j < n; ++j) {
            for (int k = j + ii; k < n; ++k) {
                int sum = nums[j] + nums[k];

                if (sum % 2) {
                    max_sum = std::max(max_sum, sum);
                }
            }
        }

        if (max_sum == INT32_MIN) {
            max_sum = 0;
        }

        ofstream << max_sum << '\n';
    }

    ofstream.close();
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
        getMaxSums(n, nums);
        nums.clear();
    }
}

void limitTest(bool negative, bool min) {
    std::vector<int> nums(100);
    ofstream.open(const_path + std::to_string(i));
    int n = 100;

    if (min) {
        n = 2;
    }

    ofstream << n << '\n';

    for (int k = 0; k < n; ++k) {
        int num;

        if (!negative) {
            num = -1000000000;
        } else {
            num = 1000000000;
        }

        ofstream << num << ' ';
        nums[k] = num;
    }

    ofstream.close();
    getMaxSums(n, nums);
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 120 << ' ' << 121;
    ofstream.close();
    getMaxSums(2, {120, 121});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 120 << ' ' << 130 << ' ' << 130 << ' ' << 140;
    ofstream.close();
    getMaxSums(4, {120, 130, 130, 140});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false, false);
    limitTest(true, false);
    limitTest(false, true);
    limitTest(true, true);
}
