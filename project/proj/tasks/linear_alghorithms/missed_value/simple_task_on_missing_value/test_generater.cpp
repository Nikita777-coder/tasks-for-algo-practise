#include "iostream"
#include "fstream"
#include "random"

std::ofstream ofstream;
int i = 1;
int const maxN = 1000;
std::string const_path = "../tasks/linear_alghorithms/missed_value/simple_task_on_missing_value/tests/0";
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> dis_n(1, maxN);
std::uniform_int_distribution<int> dis_num(0, maxN - 1);

void getMissedNum(int n, const std::vector<int> &nums) {
    ofstream.open(const_path + std::to_string(i++) + ".a");
    
    int64_t sum = (n * (n + 1)) / 2;

    for (int ii = 0; ii < n - 1; ++ii) {
        sum -= nums[ii];
    }

    ofstream << sum;

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

        for (int p = 1; p <= n; ++p) {
            nums[p - 1] = p;
        }

        int pos = dis_num(rng) % (n);
        nums.erase(nums.begin() + pos);

        for (int k = 0; k < n - 1; ++k) {
            ofstream << nums[k] << ' ';
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

    for (int p = 1; p <= n; ++p) {
        nums[p - 1] = p;
    }

    int pos = dis_num(rng) % (n);
    nums.erase(nums.begin() + pos);

    for (int k = 0; k < n - 1; ++k) {
        ofstream << nums[k] << ' ';
    }

    ofstream.close();
    getMissedNum(n, nums);
    nums.clear();
}

int main() {
    /* sample tests */
    // 1
    ofstream.open(const_path + std::to_string(i));
    ofstream << 2 << '\n' << 1;
    ofstream.close();
    getMissedNum(2, {1});

    // 2
    ofstream.open(const_path + std::to_string(i));
    ofstream << 4 << '\n' << 1 << ' ' << 3 << ' ' << 4;
    ofstream.close();
    getMissedNum(4, {1, 3, 4});

    /* random tests */
    fileSimpleTestsWriter(20);

    /* limit tests */
    limitTest(false);
    limitTest(true);
}

