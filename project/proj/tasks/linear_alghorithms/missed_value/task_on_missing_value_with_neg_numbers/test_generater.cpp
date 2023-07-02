#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 1000;
std::string const_path = "../tasks/linear_alghorithms/missed_value/task_on_missing_value_with_neg_numbers/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(3, maxN);
std::uniform_int_distribution<int> dis_num(-1000000, 1000000);
std::uniform_int_distribution<int> dis_diff(1, 100);
std::uniform_int_distribution<int> dis_pos(0, maxN - 1);

void getMissedNum(int n, const std::vector<int> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");
    
    int min_el = INT32_MAX, max_el = INT32_MIN;
    int sum = 0;

    for (int ii = 0; ii < n - 1; ++ii) {
        sum += nums[ii];
        min_el = std::min(nums[ii], min_el);
        max_el = std::max(nums[ii], max_el);
    }

    ofstream << (min_el + max_el) * n / 2 - sum;

    ofstream.close();
}

void fileSimpleTestsWriter(int count_of_tasks) {
    std::vector<int> nums(maxN);

    for (int j = 0; j < count_of_tasks; ++j) {
        if (i == 10) {
            const_path.pop_back();
        }

        ofstream.open(const_path + std::to_string(i));

        int n = dis_n(rng);
        ofstream << n << '\n';
        nums.assign(n, 0);

        int random_pos = dis_pos(rng) % n;
        int random_diff = dis_diff(rng);
        int min_el = dis_num(rng);

        for (int p = 0; p < n - 1; ++p) {
            if (p != random_pos) {
                nums[p] = min_el + random_diff * p;
            } else {
                nums[p] = min_el + random_diff * (n - 1);
            }
        }

        for (int p = 0; p < n - 1; ++p) {
            ofstream << nums[p] << ' ';
        }

        ofstream.close();
        getMissedNum(n, nums);
        nums.clear();
    }
}

void limitTest(bool min) {
    std::vector<int> nums(maxN);
    ofstream.open(const_path + std::to_string(i));
    int n = maxN;

    if (min) {
        n = 1;
    }

    int random_pos = dis_pos(rng) % n;
    int min_el = -1000000;

    for (int p = 0; p < n - 1; ++p) {
        if (p != random_pos) {
            nums[p] = min_el + 100 * p;
        } else {
            nums[p] = min_el + 100 * (n - 1);
        }
    }

    for (int p = 0; p < n - 1; ++p) {
        ofstream << nums[p] << ' ';
    }

    ofstream.close();
    getMissedNum(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 3 << '\n' << 1 << ' ' << 3;
    ofstream.close();
    getMissedNum(3, {1, 3});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << -1 << ' ' << 1 << ' ' << 5;
    ofstream.close();
    getMissedNum(4, {-1, 1, 5});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

