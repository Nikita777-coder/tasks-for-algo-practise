#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 100000;
std::string const_path = "../tasks/linear_alghorithms/max_sum_on_subsegment/simple_task/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, maxN);
std::uniform_int_distribution<int> dis_num(-10000, 10000);

void getMaxSubs(int n, const std::vector<int64_t> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");

    int64_t max_current_sum = nums[0], max_global_sum = nums[0];

    for (int ii = 1; ii < n; ++ii) {
        max_current_sum = std::max(nums[ii], max_current_sum + nums[ii]);
        max_global_sum = std::max(max_current_sum, max_global_sum);
    }

    ofstream << max_global_sum;

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int64_t> nums(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';
        nums.assign(n, 0);

        for (int p = 0; p < n; ++p) {
            nums[p] = dis_num(rng);
            ofstream << nums[p] << ' ';
        }

        ofstream.close();
        getMaxSubs(n, nums);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<int64_t> nums(maxN);

    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 1;
    }

    for (int p = 0; p < n; ++p) {
        nums[p] = min ? -10000 : 10000;
        ofstream << nums[p] << ' ';
    }

    ofstream.close();
    getMaxSubs(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 1 << ' ' << 2;
    ofstream.close();
    getMaxSubs(2, {1, 2});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 3 << ' ' << 4 << ' ' << 2;
    ofstream.close();
    getMaxSubs(4, {1, 3, 4, 2});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

